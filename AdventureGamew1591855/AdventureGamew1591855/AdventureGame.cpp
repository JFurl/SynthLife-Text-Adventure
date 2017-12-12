#include "stdafx.h"
#include "AdventureGame.h"
#include "AdditionalFunctions.h"
#include <iostream>
#include <sstream>


using namespace std;

AdditionalFunctions af;
Player player;

const bool TRUE = TRUE;

AdventureGame::AdventureGame() {

}

int AdventureGame::mainMenuLoop(ifstream& inFile, ofstream& outFile) {

	string choice;
	int choicei = 0;

	af.drawTitle();

	cout << "\n1. Start Game" << endl;
	cout << "2. Instructions" << endl;
	cout << "3. Quit\n" << endl;

	getline(cin, choice);

	choicei = af.strToInt(choice);

	switch (choicei)
	{
	case 1:
		system("cls");
		run(inFile, outFile);
		break;
	case 2:
		system("cls");
		af.drawHelp();
		break;
	case 3:
		exit(0);
		break;
	default:
		cout << "Please Enter a Valid Input." << endl;
		break;
	}
	return choicei;
}


void AdventureGame::run(ifstream& inFile, ofstream& outFile) {

	string name;
	char exitValue = '8';
	int previousRoom = 1;
	Key* startingItem = new Key("Destroyed Key", "It looks like a key but it's destroyed.");
	startingItem->setCorrispondingObject(10);
	//vector<Door*> doors;
	vector<AdventureRoom>& allRooms = readRoom(inFile, outFile);
	cout << "Please Enter Your Player Name: \n" << endl;
	getline(cin, name);
	player.setName(name);
	player.addToInventory(startingItem);
	system("cls");
	displayCurrentRoom(allRooms, player);

	while (exitValue != 'X')
	{
		exitValue = menuLoop(allRooms, previousRoom);
	}

}

char AdventureGame::menuLoop(vector<AdventureRoom>& allRooms,int& previousRoom) {

	char menuChoice;
	string input;
	bool truVal = false;
	int curRm = player.getCurrentRoom();
	allRooms[curRm - 1].setRoomVisited(TRUE);
	MotionTableEntry& motion = allRooms[curRm - 1].getMotionTable();

	cout << "\nWhat Would You Like To Do?\n" << endl;
	cout << "Type HELP for instructions." << endl;
	cin.sync();
	getline(cin, input);
	menuChoice = af.playerInput(input);

	player.addMove(previousRoom);
	previousRoom = player.getCurrentRoom();
	

	if (player.getCurrentRoom() == 6) {
		menuChoice = 'A';
	}

	switch (menuChoice)
	{
	case 'N':
		system("cls");
		for (int i = 0; i < player.getInventory().size(); i++) {
			if (motion.getDoors()[0]->getCorrispondingObject() == player.getInventory()[i]->getCorrispondingObject() || motion.getDoors()[0]->getCorrispondingObject() == 0) {
				player.setCurrentRoom(motion.getConnectingRoomN());
				truVal = true;
				break;
			}
		}
			if (!truVal) {
				cout << "This Door Is Locked.\n";
				player.setCurrentRoom(previousRoom);
			}
		
		if (player.getCurrentRoom() == 0) {
			cout << "You cannot go that way from here." << endl;
			player.setCurrentRoom(previousRoom);
		}
		displayCurrentRoom(allRooms, player);
		truVal = false;
		break;

	case 'S':
		for (int i = 0; i < player.getInventory().size(); i++) {
			if (motion.getDoors()[1]->getCorrispondingObject() == player.getInventory()[i]->getCorrispondingObject() || motion.getDoors()[1]->getCorrispondingObject() == 0) {
				player.setCurrentRoom(motion.getConnectingRoomS());
				truVal = true;
				break;
			}
		}
			if (!truVal) {
				cout << "This Door Is Locked";
				player.setCurrentRoom(previousRoom);
			}
		
		if (player.getCurrentRoom() == 0) {
			cout << "You cannot go that way from here." << endl;
			player.setCurrentRoom(previousRoom);
		}
		displayCurrentRoom(allRooms, player);
		truVal = false;
		break;

	case 'E':
		for (int i = 0; i < player.getInventory().size(); i++) {
			if (motion.getDoors()[2]->getCorrispondingObject() == player.getInventory()[i]->getCorrispondingObject() || motion.getDoors()[2]->getCorrispondingObject() == 0) {
				player.setCurrentRoom(motion.getConnectingRoomE());
				truVal = true;
				break;
			}
		}
			if (!truVal) {
				cout << "This Door Is Locked";
				player.setCurrentRoom(previousRoom);
				
			}
		
		if (player.getCurrentRoom() == 0) {
			cout << "You cannot go that way from here." << endl;
			player.setCurrentRoom(previousRoom);
		}
		displayCurrentRoom(allRooms, player);
		truVal = false;
		break;

	case 'W':
		for (int i = 0; i < player.getInventory().size(); i++) {
			if (motion.getDoors()[3]->getCorrispondingObject() == player.getInventory()[i]->getCorrispondingObject() || motion.getDoors()[3]->getCorrispondingObject() == 0) {
				player.setCurrentRoom(motion.getConnectingRoomW());
				truVal = true;
				break;
			}
		}
			if (!truVal) {
				cout << "This Door Is Locked";
				player.setCurrentRoom(previousRoom);
				
			}
		
		if (player.getCurrentRoom() == 0) {
			cout << "You cannot go that way from here." << endl;
			player.setCurrentRoom(previousRoom);
		}
		displayCurrentRoom(allRooms, player);
		truVal = false;
		break;

	case'K':
		system("cls");
		if (allRooms[curRm - 1].getObject("KEY")->getOwned() == true) {
			cout << "Nothing to pick up." << endl;
		}
		else {
			player.addToInventory(allRooms[curRm - 1].getObject("KEY"));
			cout << allRooms[curRm - 1].getObject("KEY")->getName() << " was added to your inventory." << endl;
		}
		break;

	case'B':
		system("cls");
		if (allRooms[curRm - 1].getObject("BOOK")->getOwned() == true) {
			cout << "Nothing to pick up." << endl;
		}
		else {
			player.addToInventory(allRooms[curRm - 1].getObject("BOOK"));
			cout << allRooms[curRm - 1].getObject("BOOK")->getName() << " was added to your inventory." << endl;
		}
		break;

	case 'L': 
		system("cls");
		displayCurrentRoom(allRooms, player);
		player.displayInvetoryDesc();
		break;

	case 'I':
		system("cls");
		displayCurrentRoom(allRooms, player);
		player.displayInventory();
		break;

	case'H':
		system("cls");
		af.drawHelp();
		displayCurrentRoom(allRooms, player);
		break;
	case 'A':
		system("cls");
		cout << "You Win!" << endl;
		break;
	case 'Z':
		cout << "Please Enter A Valid Input." << endl;
		displayCurrentRoom(allRooms, player);
		break;

	case'Q':
		exit(0);
		break;
	}

	return menuChoice;
}

vector<AdventureRoom> AdventureGame::readRoom(ifstream& inFile, ofstream& outFile) {

	vector<AdventureRoom> allRooms;
	string roomName;
	string description;
	string directionN, directionS, directionE, directionW;
	int corKeyN, corKeyS, corKeyE, corKeyW;
	int conN, conS, conE, conW;
	string line;
	int rmNum;
	vector<string> info;
	vector<int> corObj;


	inFile.open("Rooms.txt");
	if (inFile.is_open()) {
		while (!inFile.eof()) {

			while (getline(inFile, line, '\|')) {

				stringstream linestream(line);
				string data;

				getline(linestream, data, '\|');

				info.push_back(data);
			}
		}
	}
	inFile.close();


	while (info.size() >= 16) {
		rmNum = af.strToInt(info[0]);	//room num
		roomName = info[1];				//room name
		description = info[2] + info[3] + info[4];		//description

		directionN = info[5];			//north info
		conN = af.strToInt(info[6]);
		corObj.push_back(corKeyN = af.strToInt(info[7]));

		directionS = info[8];			//south info
		conS = af.strToInt(info[9]);
		corObj.push_back(corKeyS = af.strToInt(info[10]));

		directionE = info[11];			//east info
		conE = af.strToInt(info[12]);
		corObj.push_back(corKeyE = af.strToInt(info[13]));

		directionW = info[14];			//west info
		conW = af.strToInt(info[15]);
		corObj.push_back(corKeyW = af.strToInt(info[16]));

		vector<Door*> doors = setDoors(corObj);

		MotionTableEntry newTableEntry(rmNum, conN, conS, conE, conW, doors);
		AdventureRoom newRoom(roomName, description, rmNum, newTableEntry, inFile, af);

		allRooms.push_back(newRoom);

		corObj.erase(corObj.begin(), corObj.begin() + corObj.size());

		info.erase(info.begin(), info.begin() + 17);

	}

	player.setCurrentRoom(1);

	return allRooms;
}

void AdventureGame::displayCurrentRoom(vector<AdventureRoom>& allRooms, Player& player) {
	int curRm = player.getCurrentRoom();
	af.drawTitle(player);
	MotionTableEntry& motion = allRooms[curRm - 1].getMotionTable();
	cout << allRooms[curRm - 1].getName() << "\n" << allRooms[curRm - 1].getDescription() << endl;
}

vector<Door*> AdventureGame::setDoors(vector<int> corrispondingObject)
{
	string D = "NULL";

	vector<Door*> doors;

	for (int i = 0; i < 4; i++) {
		Door* newDoor = new Door(directions[i], D, corrispondingObject[i]);
		doors.push_back(newDoor);
	}
	return doors;
}





