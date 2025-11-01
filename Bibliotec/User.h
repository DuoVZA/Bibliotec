#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;
    int id;
    int booksTaken;

public:
    User() {
        name = "";
        id = 0;
        booksTaken = 0;
    }

    void set(string n, int i) {
        name = n;
        id = i;
        booksTaken = 0;
    }

    string getName() const { return name; }
    int getId() const { return id; }
    int getBooksTaken() const { return booksTaken; }

    void takeBook() { booksTaken++; }
    void returnBook() { if (booksTaken > 0) booksTaken--; }

    void print() const {
        cout << "ID: " << id << " | Name: " << name
            << " | Books currently borrowed: " << booksTaken << endl;
    }
};
