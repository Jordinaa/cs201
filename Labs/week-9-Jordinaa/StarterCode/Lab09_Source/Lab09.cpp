#include "LibraryBook.h"

int main() {
    // Read in the ISBNs from the isbns.txt file
    ifstream isbnFile("isbns.txt");
    vector<string> checkedOutISBNs;
    string isbn;

    while (isbnFile >> isbn) {
        checkedOutISBNs.push_back(isbn);
    }

    isbnFile.close();

    // Read in the book information from the books.txt file
    ifstream bookFile("books.txt");
    vector<LibraryBook> books;
    string title, author, ISBN;

    while (getline(bookFile, title) && getline(bookFile, author) && getline(bookFile, ISBN)) {
        LibraryBook book(title, author, ISBN);
        books.push_back(book);
    }

    bookFile.close();

    // Check in/out the books based on the ISBNs
    for (auto& book : books) {
        if (find(checkedOutISBNs.begin(), checkedOutISBNs.end(), book.getISBN()) != checkedOutISBNs.end()) {
            book.checkOut();
        } else {
            book.checkIn();
        }
    }

    // Write out the checked out books to a file
    ofstream checkedOutFile("checkedout.txt");
    checkedOutFile << "Books checked out:\n\n";
    checkedOutFile << "------------------\n";
    checkedOutFile << "Title\tAuthor\tISBN\n";

    for (const auto& book : books) {
        if (book.isCheckedOut()) {
            checkedOutFile << book.getTitle() << "\t" << book.getAuthor() << "\t" << book.getISBN() << "\n";
        }
    }

    checkedOutFile.close();
    return 0;
}
