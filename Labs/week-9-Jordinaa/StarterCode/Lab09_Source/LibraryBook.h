#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class LibraryBook {
public:
    LibraryBook();
    LibraryBook(string title, string author, string ISBN);

    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    bool isCheckedOut() const;
    void checkOut();
    void checkIn();

private:
    string title;
    string author;
    string ISBN;
    bool checkedOut;
};
