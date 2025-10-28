#include "Bibliotec.h"

Bibliotec::Bibliotec()
{

}

void Bibliotec::Print(Bibliotec obj)
{
	cout << "------------------------------------------------\n"
		<< "Book: " << book
		<< "\nAuthor: " << author
		<< "\nGenre: " << genre
		<< "\nHas smbd this book? - " << isTaken;
		if (isTaken)
		{
			cout << "\nWho?"
				<< "\n\tName: " << name
				<< "\n\tID: " << id
				<< "\n------------------------------------------------";
		}
}

void Bibliotec::Add()
{
	char buff[100];
	cout << "------------------------------------------------\n"
		<< "Book: ";
	cin.getline(buff, 100);
	this->book = buff;
	cout << "\nAuthor: ";
	cin.getline(buff, 100);
	this->author = buff;
	cout << "\nGenre: ";
	cin.getline(buff, 100);
	this->genre = buff;
	cout << "\nHas smbd this book?(true/false) - ";
	cin >> isTaken;
	if (isTaken)
	{
		cout << "\nWho?";
		cout << "\n\tName: ";
		cin.getline(buff, 100);
		this->name = buff;
		cout << "\n\tID: ";
		cin >> id;
	}
	cout << "\n------------------------------------------------";
}

Bibliotec::~Bibliotec()
{
	delete book;
	delete author;
	delete genre;

	delete name;
	id = 0;
}

Bibliotec& Bibliotec::operator=(Bibliotec& obj)
{

}
