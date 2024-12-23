import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ").strip().title()
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    citys = {}
    for row in reader:
        state = str(row['state'])
        cases = int(row['cases'])

        if state not in citys:
            citys[state]=[]

        if len(citys[state])<14:
            citys[state].append(cases)
        else:
            citys[state].remove(citys[state][0])
            citys[state].append(cases)

    return citys

# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        last  = sum(new_cases[state][7:])
        before = sum(new_cases[state][:7])
        try :
            if last>before:
                percentage = (last/before*100)-100
                print(f"{state} had a 7-day average of {int(last/7)} and an increase of {percentage:.3%}.")
            elif last<before:
                percentage = 100-(last/before*100)
                print(f"{state} had a 7-day average of {int(last/7)} and an decrease of {percentage:.3%}.")
            else:
                print(f"{state} had a 7-day average of {int(last/7)} and same as before.")
        except ZeroDivisionError:
            pass
main()
