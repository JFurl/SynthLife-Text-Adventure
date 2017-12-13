#include "stdafx.h"
#include "Door.h"

Door::Door() {

}

Door::Door(string name, string description, int corrispondingObject):Object(name, description)
{
	setCorrispondingObject(corrispondingObject);
}

string Door::type() {
	return "DOOR";
}

string Door::examine()
{
	return getDescription();
}

/*string Door::useWith(Object* object) 
{
	if (object->getCorrispondingObject() > 0 && object->getCorrispondingObject() == getCorrispondingObject()) {
		return this->open();
	}
	else {
		return object->getName() + " Does not open this door";
	}
}*/

string Door::open()
{
	return getName() + " Is Now Open";
}

bool Door::getState() {
	return doorState;
}

