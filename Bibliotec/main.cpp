#include <iostream>
#include <string>
#include "Bibliotec.h"
using namespace std;

ostream& operator << (ostream& os, Bibliotec& obj)
{
	os << obj << endl;
	return os;
}

int main()
{
	Bibliotec book1("Name", "Author", "Genre", true, "Name2", 12345);

	book1.Print();
}

