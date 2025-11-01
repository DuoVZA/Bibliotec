#pragma once
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string genre;
    bool isTaken;
    string borrowerName;
    int borrowerId;

public:
    Book() {
        title = "";
        author = "";
        genre = "";
        isTaken = false;
        borrowerName = "";
        borrowerId = 0;
    }

    void set(string t, string a, string g) {
        title = t;
        author = a;
        genre = g;
        isTaken = false;
        borrowerName = "";
        borrowerId = 0;
    }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    bool getTaken() const { return isTaken; }
    string getBorrowerName() const { return borrowerName; }
    int getBorrowerId() const { return borrowerId; }

    void takeBook(string name, int id) {
        isTaken = true;
        borrowerName = name;
        borrowerId = id;
    }

    void returnBook() {
        isTaken = false;
        borrowerName = "";
        borrowerId = 0;
    }

    void print() const {
        cout << "--------------------------------------\n";
        cout << "Title: " << title << "\nAuthor: " << author << "\nGenre: " << genre;
        cout << "\nStatus: " << (isTaken ? "Checked out" : "Available");
        if (isTaken) {
            cout << "\nBorrowed by: " << borrowerName << " (ID: " << borrowerId << ")";
        }
        cout << "\n--------------------------------------\n";
    }
};
