#ifndef MOTIONTABLEENTRY_H
#define MOTIONTABLEENTRY_H
#include "stdafx.h"
#include "Door.h"
#include <vector>

class MotionTableEntry
{
public:
	MotionTableEntry();

	MotionTableEntry(int, int, int, int, int, vector<Door*>);

	int getConnectingRoomN();

	void setConnectingRoomN(int);

	int getConnectingRoomS();

	void setConnectingRoomS(int);

	int getConnectingRoomE();

	void setConnectingRoomE(int);

	int getConnectingRoomW();

	void setConnectingRoomW(int);

	int getAttachedRoom();

	void setAttachedRoom(int);

	vector<Door*> getDoors();


private:
	int rmNum, rmConnectedN, rmConnectedS, rmConnectedE, rmConnectedW;
	vector<Door*> doors;
	
};

#endif
