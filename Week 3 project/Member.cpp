#include "Member.h"
#include <iostream>

Member::Member() : name("") {}

Member::Member(const std::string& name) : name(name) {}

std::string Member::getName() const { return name; }

void Member::borrowBook(Book& book) {
    if (book.isAvailable()) {
        book.borrowBook();
        borrowedBooks.push_back(book);
    }
}

void Member::returnBook(Book& book) {
    for (size_t i = 0; i < borrowedBooks.size(); i++) {
        if (borrowedBooks[i].getTitle() == book.getTitle()) {
            book.returnBook();
            borrowedBooks.erase(borrowedBooks.begin() + i);
            break;
        }
    }
}

void Member::displayBorrowedBooks() const {
    std::cout << "Books borrowed by " << name << ":\n";
    for (const auto& book : borrowedBooks) {
        std::cout << book.getTitle() << " by " << book.getAuthor() << " (" << book.getYear() << ")\n";
    }
}
