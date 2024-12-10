library = []

# 1
def add_new_book():
    title = input("Enter book title: ")
    cost = int(input("Enter book cost: "))
    library.append({'title': title, 'cost': cost})
    print("Book added.")
    
# 2
def delete_duplicates():
    unique_books = []
    for book in library:
        if book not in unique_books:
            unique_books.append(book)
    library.clear()
    library = unique_books
    print("Duplicates removed.")

# 3
def display_books_sorted():
    def book_price(book):
        return book["cost"]
    sorted_books = sorted(library, key = book_price)
    for book in sorted_books:
        print("Title: ", book['title'], " || Cost: ", book['cost'])
        
# 4
def count_books_above_500():
    count = 0
    for book in library:
        if book["cost"] > 500:
            count += 1
    print("Books costing more than 500: ", count)

# 5
def copy_books_below_500():
    for book in library:
        if book["cost"] < 500:
            new_list.append(book)
    print("Books with cost less than 500: ")
    for book in new_list:
        print("Title: ", book['title'], " || Cost: ", book['cost'])


while True:
    print("\nMenu:")
    print("1. Add new book")
    print("2. Delete duplicates")
    print("3. Display books sorted by cost")
    print("4. Count books costing more than 500")
    print("5. Copy books costing less than 500")
    print("6. Exit")
    choice = input("Choose an option: ")

    if choice == '1' :
        add_new_book()
    elif choice == '2' :
        delete_duplicates()
    elif choice == '3' :
        display_books_sorted()
    elif choice == '4' :
        count_books_above_500()
    elif choice == '5' :
        copy_books_below_500()
    else :
        print("Exiting. Goodbye!")
        break