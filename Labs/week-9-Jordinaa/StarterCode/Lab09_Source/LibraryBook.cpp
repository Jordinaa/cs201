#include "LibraryBook.h"

LibraryBook::LibraryBook() : title(""), author(""), ISBN(""), checkedOut(false) {}

LibraryBook::LibraryBook(string title, string author, string ISBN) : 
    title(title), author(author), ISBN(ISBN), checkedOut(false) {}

string LibraryBook::getTitle() const {
    return title;
}

string LibraryBook::getAuthor() const {
    return author;
}

string LibraryBook::getISBN() const {
    return ISBN;
}

bool LibraryBook::isCheckedOut() const {
    return checkedOut;
}

void LibraryBook::checkOut() {
    checkedOut = true;
}

void LibraryBook::checkIn() {
    checkedOut = false;
}
