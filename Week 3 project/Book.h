#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;
    bool available;  // Added to handle availability

public:
    // Constructors
    Book();
    Book(const std::string& title, const std::string& author, int year, bool available = true);

    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    int getYear() const;
    bool isAvailable() const;

    // Methods to borrow and return the book
    void borrowBook();
    void returnBook();
};

#endif // BOOK_H
