#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Book.h"

class Member {
private:
    std::string name;
    std::vector<Book> borrowedBooks;

public:
    Member();
    Member(const std::string& name);

    std::string getName() const;
    void borrowBook(Book& book);
    void returnBook(Book& book);

    void displayBorrowedBooks() const;
};

#endif // MEMBER_H
