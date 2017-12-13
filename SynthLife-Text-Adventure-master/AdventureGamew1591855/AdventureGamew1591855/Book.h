#ifndef BOOK_H
#define BOOK_H
#include "Object.h"

class Book :public Object
{
public:
	Book();

	Book(string, string);

	string type();

	string examine();

	//string useWith(Object*);

	string open();

private:

};


#endif
