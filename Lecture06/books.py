books = []

titles = ["1.kitap", "2.kitap", "3.kitap"]
authors = ["1.yazar", "2.yazar", "3.yazar"]
for i in range(3):
    book = {"title": titles[i], "author": authors[i]}
    books.append(book)

for book in books:
    print(f"Title: {book['title']} Author: {book['author']}")