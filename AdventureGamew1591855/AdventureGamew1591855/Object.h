#ifndef OBJECT_H
#define OBJECT_H
#include "stdafx.h"
#include <string>
using namespace std;

class Object
{
public:
	Object();

	Object(string, string);

	virtual string type() = 0; // returns the type of object

	virtual string examine() = 0; // returns description of object

	//virtual string useWith() = 0;	//check for object interactions

	virtual string open() =0; //used for specific objects such as containers or doors

	string getName(); // returns name of Object

	void setName(string);	//sets name of object

	string getDescription(); //returns description of object

	void setDescription(string); //sets description of object

	bool getOwned(); // returns bool used to check if player has picked up object

	void setOwned(bool); // set bool to check if player has picked up opbject 

	int getCorrispondingObject(); //int value that denotes a connection between two object such a key and door/container

	void setCorrispondingObject(int n); //set int to same as a corrisponding object

private:
	string name;	//name of object
	string description;	 //description of object
	bool owned;	//used to check if object has been picked up by player
	int corrispondingObject;
};

#endif

