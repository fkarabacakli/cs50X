import csv

with open("phonebook.csv", "a") as csv_file:

    name= input("Name:")
    number= input("Number: ")

    writer = csv.DictWriter(csv_file, fieldnames=["name", "phone number"])
    writer.writerow({"name":name, "phone number":number})


