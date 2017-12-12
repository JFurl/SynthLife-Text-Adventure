#ifndef ADDITIONALFUNCTIONS_H
#define ADDITIONALFUNCTIONS_H
#include "stdafx.h"
#include <sstream>
#include <string>
#include <iostream>
#include "Player.h"

using namespace std;

class AdditionalFunctions
{

private:
	enum colours
	{
		black = 0,
		dark_blue = 1,
		dark_green = 2,
		dark_aqua, dark_cyan = 3,
		dark_red = 4,
		dark_purple = 5, dark_pink = 5, dark_magenta = 5,
		dark_yellow = 6,
		dark_white = 7,
		gray = 8,
		blue = 9,
		green = 10,
		aqua = 11, cyan = 11,
		red = 12,
		purple = 13, pink = 13, magenta = 13,
		yellow = 14,
		white = 15
	};
	
public:
	
	AdditionalFunctions(); // default constructor

	int strToInt(string);	// does what it says on the tin. Put in a string and out pops its int value.

	char playerInput(string);	// checks player input and returns a char related to the command.

	string lowerToUpper(string);	//makes all strings passed to it uppercase for simpler checking.

	void drawTitle(Player&);

	void drawTitle();

	void setColour(colours, colours);

	void drawHelp();


};

#endif