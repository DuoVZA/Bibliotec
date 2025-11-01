#include "Bibliotec.h"
#include <iostream>
using namespace std;

int main() {
    Bibliotec lib;

    // Preload some users and books
    lib.addUser("John Smith", 101);
    lib.addUser("Emily Clark", 102);
    lib.addBook("The Hobbit", "J.R.R. Tolkien", "Fantasy");
    lib.addBook("1984", "George Orwell", "Dystopia");
    lib.addBook("To Kill a Mockingbird", "Harper Lee", "Classic");

    int choice;
    string title, author, genre, name;
    int id;

    do {
        cout << "\n======= LIBRARY MENU =======\n";
        cout << "1. Show all books\n";
        cout << "2. Search by title\n";
        cout << "3. Search by author\n";
        cout << "4. Search by genre\n";
        cout << "5. Give book to user\n";
        cout << "6. Return book\n";
        cout << "7. Show most frequent user\n";
        cout << "8. Add user\n";
        cout << "9. Add book\n";
        cout << "0. Exit\n> ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            lib.showAllBooks();
            break;
        case 2:
            cout << "Enter title: ";
            getline(cin, title);
            lib.searchByTitle(title);
            break;
        case 3:
            cout << "Enter author: ";
            getline(cin, author);
            lib.searchByAuthor(author);
            break;
        case 4:
            cout << "Enter genre: ";
            getline(cin, genre);
            lib.searchByGenre(genre);
            break;
        case 5:
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter user ID: ";
            cin >> id;
            lib.giveBook(title, id);
            break;
        case 6:
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter user ID: ";
            cin >> id;
            lib.returnBook(title, id);
            break;
        case 7:
            lib.mostFrequentUser();
            break;
        case 8:
            cout << "Enter user name: ";
            getline(cin, name);
            cout << "Enter user ID: ";
            cin >> id;
            lib.addUser(name, id);
            break;
        case 9:
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter genre: ";
            getline(cin, genre);
            lib.addBook(title, author, genre);
            break;
        }
    } while (choice != 0);

    cout << "Program finished. Goodbye!\n";
    return 0;
}
