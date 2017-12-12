#ifndef PLAYER_H
#define PLAYER_H
#include "stdafx.h"
#include "Object.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Player {
public:

	Player();

	Player(string);

	string getName();

	void setName(string n);

	int getHealth();

	void setHealth(int h);

	vector<Object*> getInventory();

	void displayInventory();

	void displayInvetoryDesc();

	void addToInventory(Object* object);

	void removeFromInventory(Object* object);

	int getCurrentRoom();

	void setCurrentRoom(int);

	int getMoves();
	
	void setMoves(int);

	void addMove();

private:
	string name;
	int health;
	vector<Object*> inventory;
	int currentRoom;
	int moves;
};
#endif 
