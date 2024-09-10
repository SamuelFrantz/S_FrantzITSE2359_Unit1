#include "Book.h"
#include <iostream>

// Default Constructor
Book::Book() : title(""), author(""), year(0), available(true) {}

// Parameterized Constructor
Book::Book(const std::string& title, const std::string& author, int year, bool available)
    : title(title), author(author), year(year), available(available) {}

// Getters
std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
int Book::getYear() const { return year; }
bool Book::isAvailable() const { return available; }

// Method to borrow the book (set available to false)
void Book::borrowBook() {
    if (available) {
        available = false;
    }
}

// Method to return the book (set available to true)
void Book::returnBook() {
    available = true;
}
