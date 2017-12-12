#include "stdafx.h"
#include "AdditionalFunctions.h"
#include "Player.h"
#include <Windows.h>

#define std_con_out GetStdHandle(STD_OUTPUT_HANDLE)

AdditionalFunctions::AdditionalFunctions() {

}

int AdditionalFunctions::strToInt(string s) {

	stringstream l(s);

	int x = 0;

	l >> x;

	return x;
}

char AdditionalFunctions::playerInput(string s1) {

	string s2 = lowerToUpper(s1);
	string n = "NORTH";
	string s = "SOUTH";
	string e = "EAST";
	string w = "WEST";
	string t = "TAKE";
	string k = "KEY";
	string b = "BOOK";
	string q = "QUIT";
	string l = "LOOK";
	string i = "INVENTORY";

	if (s2.find(n) != string::npos) {
		return 'N';
	}

	else if (s2.find(s) != string::npos) {
		return 'S';
	}

	else if (s2.find(e) != string::npos) {
		return 'E';
	}

	else if (s2.find(w) != string::npos) {
		return 'W';
	}
	else if (s2.find(t) != string::npos) {
		if (s2.find(k) != string::npos) {
			return 'K';
		}
		else if (s2.find(b) != string::npos) {
			return 'B';
		}
	}
	else if (s2.find(q) != string::npos) {
		return 'Q';
	}
	else if (s2.find(l) != string::npos) {
		return 'L';
	}
	else if (s2.find(i) != string::npos) {
		return 'I';
	}
	else {
		return 'Z';
	}

}

string AdditionalFunctions::lowerToUpper(string input) {

	string upper;

	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) >= 97 && input.at(i) <= 122) {
			upper += (input.at(i) - 32);
		}
		else {
			upper += input.at(i);
		}
	}

	return upper;

}
void AdditionalFunctions::setColour(colours text, colours console)
{
	unsigned short wAttributes = (console << 4) | text;
	SetConsoleTextAttribute(std_con_out, wAttributes);
}

void AdditionalFunctions::drawTitle(Player& player) {
	setColour(green, black);
	
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------****---*-----*---**-----*---*******---*----*---*--------*******---*******---*******--------------------" << endl;
	cout << "-----------*--------*---*----*-*----*------*------*----*---*-----------*------*---------*--------------------------" << endl;
	cout << "-----------*---------*-*-----*--*---*------*------*----*---*-----------*------*---------*--------------------------" << endl;
	cout << "------------****------*------*---*--*------*------******---*-----------*------*******---*******--------------------" << endl;
	cout << "----------------*-----*------*----*-*------*------*----*---*-----------*------*---------*--------------------------" << endl;
	cout << "----------------*-----*------*-----**------*------*----*---*-----------*------*---------*--------------------------" << endl;
	cout << "------------****------*------*------*------*------*----*---******---*******---*---------*******--------------------" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	setColour(red, black);
	cout << "Player: " << player.getName() << "     Moves: " << player.getMoves() << endl;
	setColour(white, black);
	
}

void AdditionalFunctions::drawTitle() {
	setColour(green, black);

	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------****---*-----*---**-----*---*******---*----*---*--------*******---*******---*******--------------------" << endl;
	cout << "-----------*--------*---*----*-*----*------*------*----*---*-----------*------*---------*--------------------------" << endl;
	cout << "-----------*---------*-*-----*--*---*------*------*----*---*-----------*------*---------*--------------------------" << endl;
	cout << "------------****------*------*---*--*------*------******---*-----------*------*******---*******--------------------" << endl;
	cout << "----------------*-----*------*----*-*------*------*----*---*-----------*------*---------*--------------------------" << endl;
	cout << "----------------*-----*------*-----**------*------*----*---*-----------*------*---------*--------------------------" << endl;
	cout << "------------****------*------*------*------*------*----*---******---*******---*---------*******--------------------" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
	setColour(white, black);
}

void AdditionalFunctions::drawHelp() {
	cout << "How to Play" << endl;
	cout << "------------" << endl;
	cout << "Work your way through all the rooms to the end to win." << endl;
	cout << "INVENTORY - typing this will bring up the names of the items you've picked up." << endl;
	cout << "TAKE KEY - typing this will put any key in the current room in your inventory." << endl;
	cout << "TAKE BOOK - typing this will put any book in the current room in your inventory." << endl;
	cout << "NORTH, SOUTH, EAST, WEST - typing any of these will move your to a differnt room." << endl;
	cout << "LOOK - typing this will display all the descriptions of the items in your inventory." << endl;
	cout << "------------\n" << endl;
}
