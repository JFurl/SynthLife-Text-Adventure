#ifndef KEY_H
#define KEY_H
#include "Object.h"

class Key : public Object {

public:

	Key();

	Key(string, string);

	string type();

	string examine();

	string useWith(Object&);

	string open();


private:
	

};

#endif