#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "Member.h"  // Include the Member class header file
#include <vector>

class Library {
private:
    std::vector<Book> inventory;  // Renamed from `books` to `inventory` to match style
    std::vector<Member> members;  // Use the correct Member class type

public:
    void addBook(const Book& book);
    void addMember(const Member& member);

    void borrowBook(const std::string& bookTitle, Member& member);
    void returnBook(const std::string& bookTitle, Member& member);

    void displayAvailableBooks() const;
};

#endif // LIBRARY_H
