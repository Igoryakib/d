#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Book {
    string author;
    string title;
    int year;
    string notes;
};

bool compareByAuthor(const Book& a, const Book& b) {
    return a.author < b.author;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int SIZE = 20;
    Book books[SIZE];

    for (int i = 0; i < SIZE; i++) {
        std::cout << "¬вед≥ть автора, назву, р≥к виданн€ та прим≥тки дл€ книги " << i + 1 << ": ";
        std::cin >> books[i].author >> books[i].title >> books[i].year;
        std::getline(std::cin, books[i].notes);
    }

    sort(books, books + SIZE, compareByAuthor);

    for (int i = 0; i < SIZE; i++) {
        cout << books[i].author << ", " << books[i].title << ", " << books[i].year << ", " << books[i].notes << std::endl;
    }

    string searchAuthor;
    cout << "¬вед≥ть автора, книги €кого ви хочете знайти: ";
    cin >> searchAuthor;

    for (int i = 0; i < SIZE; i++) {
        if (books[i].author == searchAuthor) {
            cout << books[i].author << ", " << books[i].title << ", " << books[i].year << ", " << books[i].notes << std::endl;
        }
    }

    return 0;
}
