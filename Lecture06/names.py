import sys

names = ["Furkan", "Semih", "Adem", "Mehmet", "Ahmet", "Eşref", "Sezer"]
name = input("Name: ").strip().title()
if name in names:
    print("Found")
    sys.exit(1)
else:
    print("Not found.")
    sys.exit(0)