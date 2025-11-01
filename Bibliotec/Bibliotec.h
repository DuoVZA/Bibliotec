#pragma once
#include "Book.h"
#include "User.h"

class Bibliotec {
private:
    static const int MAX_BOOKS = 100;
    static const int MAX_USERS = 50;

    Book books[MAX_BOOKS];
    User users[MAX_USERS];

    int bookCount;
    int userCount;

public:
    Bibliotec() {
        bookCount = 0;
        userCount = 0;
    }

    void addBook(string title, string author, string genre) {
        if (bookCount >= MAX_BOOKS) {
            cout << "❌ No more space for books.\n";
            return;
        }
        books[bookCount].set(title, author, genre);
        bookCount++;
        cout << "✅ Book added successfully!\n";
    }

    void addUser(string name, int id) {
        if (userCount >= MAX_USERS) {
            cout << "❌ No more space for users.\n";
            return;
        }
        users[userCount].set(name, id);
        userCount++;
        cout << "✅ User added successfully!\n";
    }

    void showAllBooks() const {
        if (bookCount == 0) {
            cout << "No books in the library.\n";
            return;
        }
        for (int i = 0; i < bookCount; i++) {
            books[i].print();
        }
    }

    void searchByTitle(string title) const {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                books[i].print();
                found = true;
            }
        }
        if (!found) cout << "No books found with that title.\n";
    }

    void searchByAuthor(string author) const {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getAuthor() == author) {
                books[i].print();
                found = true;
            }
        }
        if (!found) cout << "No books found by that author.\n";
    }

    void searchByGenre(string genre) const {
        bool found = false;
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getGenre() == genre) {
                books[i].print();
                found = true;
            }
        }
        if (!found) cout << "No books found in that genre.\n";
    }

    void giveBook(string title, int userId) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title && !books[i].getTaken()) {
                for (int j = 0; j < userCount; j++) {
                    if (users[j].getId() == userId) {
                        if (users[j].getBooksTaken() >= 3) {
                            cout << "❌ This user already has 3 books.\n";
                            return;
                        }
                        books[i].takeBook(users[j].getName(), userId);
                        users[j].takeBook();
                        cout << "✅ Book successfully checked out!\n";
                        return;
                    }
                }
            }
        }
        cout << "❌ Book not found or already checked out.\n";
    }

    void returnBook(string title, int userId) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title && books[i].getBorrowerId() == userId) {
                for (int j = 0; j < userCount; j++) {
                    if (users[j].getId() == userId) {
                        books[i].returnBook();
                        users[j].returnBook();
                        cout << "✅ Book successfully returned!\n";
                        return;
                    }
                }
            }
        }
        cout << "❌ Could not find this loan record.\n";
    }

    void mostFrequentUser() const {
        if (userCount == 0) {
            cout << "No users in the system.\n";
            return;
        }

        int maxBooks = -1;
        int index = -1;

        for (int i = 0; i < userCount; i++) {
            if (users[i].getBooksTaken() > maxBooks) {
                maxBooks = users[i].getBooksTaken();
                index = i;
            }
        }

        if (index >= 0) {
            cout << "📚 Most frequent visitor:\n";
            users[index].print();
        }
    }
};
