#ifndef ADVENTUREROOM_H
#define ADVENTUREROOM_H
#include "stdafx.h"
#include "Key.h"
#include "Book.h"
#include "MotionTableEntry.h"
#include "AdditionalFunctions.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class AdventureRoom {
public:
	AdventureRoom();

	AdventureRoom(string, string, int, MotionTableEntry, ifstream&, AdditionalFunctions&);

	string getName();

	string getDescription();

	int getRoomNum();

	bool getRoomVisisted();

	void setRoomVisited(bool);

	MotionTableEntry getMotionTable();

	Object* getObject(string);

	vector<Object*> readObjects(ifstream&, AdditionalFunctions&);

	

private:
	string name;
	string description;
	int rmNum;
	bool visited;
	vector<Object*> rmObjs;
	MotionTableEntry motionTable;
	
};

#endif
