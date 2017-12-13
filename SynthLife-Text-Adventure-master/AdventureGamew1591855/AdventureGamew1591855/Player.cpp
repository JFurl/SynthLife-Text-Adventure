#include "stdafx.h"
#include "Player.h"


using namespace std;

Player::Player() {

}

Player::Player(string n) {
	setName(n);
}

string Player::getName() {
	return name;
}

void Player::setName(string n) {
	name = n;
}

int Player::getHealth() {
	return health;
}

void Player::setHealth(int h) {
	health = h;
}

vector<Object*> Player::getInventory() {
	return inventory;
}

void Player::displayInventory() {

	cout << "\nINVENTORY" << endl;
	cout << "---------" << endl;

	for (int i = 0; i < inventory.size(); i++) {
		cout << inventory[i]->getName() << endl;
	}	

	cout << "---------" << endl;
}

void Player::displayInvetoryDesc() {

	cout << "\nINVENTORY" << endl;
	cout << "---------" << endl;

	for (int i = 0; i < inventory.size(); i++) {
		cout << inventory[i]->getName() << endl;
		cout << inventory[i]->getDescription() << endl;
	}

	cout << "---------" << endl;
}

void Player::addToInventory(Object* object) {
	inventory.push_back(object);
	object->setOwned(true);
}

void Player::removeFromInventory(Object* object) {
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i]->getName() == object->getName()) {
			inventory.erase (inventory.begin()+i);
			object->setOwned(false);
		}
		
	}
}

int Player::getCurrentRoom() {
	return currentRoom;
}

void Player::setCurrentRoom(int c) {
	currentRoom = c;
}

int Player::getMoves() {
	return moves;
}

void Player::setMoves(int m) {
	moves = m;
}

void Player::addMove(int pr) {
	if (pr != getCurrentRoom())
	{
		moves++;
	}

}

