#include "Library.h"
#include <iostream>

void Library::addBook(const Book& book) {
    inventory.push_back(book);
}

void Library::addMember(const Member& member) {
    members.push_back(member);
}

void Library::borrowBook(const std::string& bookTitle, Member& member) {
    for (auto& book : inventory) {
        if (book.getTitle() == bookTitle && book.isAvailable()) {
            member.borrowBook(book);
            break;
        }
    }
}

void Library::returnBook(const std::string& bookTitle, Member& member) {
    for (auto& book : inventory) {
        if (book.getTitle() == bookTitle && !book.isAvailable()) {
            member.returnBook(book);
            break;
        }
    }
}

void Library::displayAvailableBooks() const {
    std::cout << "Available books:\n";
    for (const auto& book : inventory) {
        if (book.isAvailable()) {
            std::cout << book.getTitle() << " by " << book.getAuthor() << " (" << book.getYear() << ")\n";
        }
    }
}
