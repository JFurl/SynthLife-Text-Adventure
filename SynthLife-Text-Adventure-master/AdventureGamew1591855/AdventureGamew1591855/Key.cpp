#include "stdafx.h"
#include "Key.h"


Key::Key() {

}

Key::Key(string name, string description):Object(name, description)
{

}

string Key::type() {
	return "KEY";
}

string Key::examine()
{
	return getDescription();
}

string Key::useWith(Object& object)
{
	return getName();
}

string Key::open()
{
	return "This is a Key. It cannot be opened.";
}
