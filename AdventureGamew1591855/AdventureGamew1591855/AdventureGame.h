#ifndef ADVENTUREGAME_H
#define ADVENTUREGAME_H
#include "stdafx.h"
#include "AdventureRoom.h"
#include "Door.h"
#include "Key.h"
#include "MotionTableEntry.h"
#include "Object.h"
#include "Player.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class AdventureGame
{
private:
	string directions[4] = { "NORTH", "SOUTH", "EAST", "WEST" };

public:

	AdventureGame();

	int mainMenuLoop(ifstream&, ofstream&);

	void run(ifstream&, ofstream&);

	char menuLoop(vector<AdventureRoom>&, int&, vector<string>&);

	vector<AdventureRoom> readRoom(ifstream&, ofstream&);

	void displayCurrentRoom(vector<AdventureRoom>&, Player&);

	vector<Door*> setDoors(vector<int>);

	void checkMotion(int, int, Player&, MotionTableEntry&, bool&);
};

#endif