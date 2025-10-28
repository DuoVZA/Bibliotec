#include <iostream>
#include <string>
#include "Bibliotec.h"
using namespace std;

ostream& operator << (ostream& os, Bibliotec& obj)
{
	os << obj << endl;
}