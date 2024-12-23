from csv import DictReader

books = []

with open("books.csv", "r", encoding='utf-8-sig') as file:
    reader = DictReader(file)
    for row in reader:
        books.append(row)

for book in books:
    print(f"{book['title']} writed by {book['author']}")