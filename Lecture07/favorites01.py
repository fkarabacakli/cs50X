import csv

languages = {}
problems = {}

with open("Lecture07/favorites.csv", "r") as dosya:
    reader = csv.DictReader(dosya)
    for row in reader:
        
        if row['language'] not in languages:
            languages.update({row['language']:1})
        else:
            languages[row["language"]] += 1

        if row['problem'] not in problems:
            problems.update({row['problem']:1})
        else:
            problems[row['problem']] += 1

string = input("Favorite: ").strip().title()

if string in languages:
    print(string,languages[string])
elif string in problems:
    print(string,problems[string])
else:
    print("Could not found!!!")
