#include "stdafx.h"
#include "Object.h"

Object::Object() {

}

Object::Object(string n, string d) {
	setName(n);
	setDescription(d);
}

string Object::getName() {
	return name;
}

void Object::setName(string n) {
	name = n;
}

string Object::getDescription() {
	return description;
}

void Object::setDescription(string d) {
	description = d;
}

bool Object::getOwned() {
	return owned;
}

void Object::setOwned(bool x) {
	owned = x;
}

int Object::getCorrispondingObject() {
	return corrispondingObject;
}

void Object::setCorrispondingObject(int n) {
	corrispondingObject = n;
}