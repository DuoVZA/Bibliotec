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
	Bibliotec(str bk, str aut, str gn, bool it, str nm, l id_);

	void Print();
	void Add();

	~Bibliotec();

	/*Bibliotec& operator = (Bibliotec& obj);	*/
};

