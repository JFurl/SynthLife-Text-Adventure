#ifndef DOOR_H
#define DOOR_H
#include "Object.h"
#include <vector>

class Door : public Object {

public:

	Door();

	Door(string, string, int) ;

	string type();

	string examine();

	//string useWith(Object*);

	string open();

	bool getState();

private:

	bool doorState;

};

#endif