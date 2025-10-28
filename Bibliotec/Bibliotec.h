#pragma once
#include <iostream>
#include <string>
using namespace std;

class Bibliotec
{
	typedef long l;
	typedef string str;
	str book;
	str author;
	str genre;

	bool isTaken;

	str name;
	l id;
public:

	Bibliotec();
	void Print(Bibliotec obj);
	void Add();

	~Bibliotec();

	Bibliotec& operator = (Bibliotec& obj);	
};

