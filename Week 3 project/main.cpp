#include "Book.h"
#include "Library.h"
#include "Member.h"
#include <iostream>

int main() {
    Library library;

    // Adding books
    library.addBook(Book("1984", "George Orwell", 1949));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));

    // Adding members
    Member member1("Alice");
    Member member2("Bob");

    library.addMember(member1);
    library.addMember(member2);

    std::cout << "\nAvailable books:\n";
    library.displayAvailableBooks();
    std::cout << std::endl;

    // Borrow and return books
    library.borrowBook("1984", member1);
    library.displayAvailableBooks();
    std::cout << std::endl;

    member1.displayBorrowedBooks();
    member2.displayBorrowedBooks();

    library.returnBook("1984", member1);
    std::cout << std::endl;
    library.displayAvailableBooks();

    return 0;
}
