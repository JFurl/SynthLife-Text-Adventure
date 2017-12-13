#include "stdafx.h"
#include "AdventureRoom.h"




AdventureRoom::AdventureRoom() {

}

AdventureRoom::AdventureRoom(string n, string d, int rm, MotionTableEntry mT, ifstream& inFile, AdditionalFunctions& af) {
	name = n;
	description = d;
	rmNum = rm;
	visited = false;
	motionTable = mT;
	rmObjs = readObjects(inFile, af);
}

string AdventureRoom::getName() {
	return name;
}

string AdventureRoom::getDescription() {
	return description;
}

int AdventureRoom::getRoomNum() {
	return rmNum;
}

bool AdventureRoom::getRoomVisisted() {
	return visited;
}

void AdventureRoom::setRoomVisited(bool visisted) {
	this->visited = visisted;
}

MotionTableEntry AdventureRoom::getMotionTable() {
	return motionTable;
}

Object* AdventureRoom::getObject(string type) {
	if (rmObjs.size > 0) {
		for (int i = 0; i < rmObjs.size(); i++)
		{
			if (rmObjs[i]->type() == type) {
				return rmObjs[i];
			}
		}
	}
}

vector<Object*> AdventureRoom::readObjects(ifstream& inFile, AdditionalFunctions& af) {

	string line;
	string name;
	string description;
	int corrispondingItem = 0;
	vector<string> objData;
	vector<Object*> rmObjs;

	inFile.open("Objects.txt");
	if (inFile.is_open()) {
		while (!inFile.eof()) {

			while (getline(inFile, line, '\|')) {

				stringstream linestream(line);
				string data;

				getline(linestream, data, '\|');

				objData.push_back(data);
			}
		}
	}
	inFile.close();




	while (objData.size() >= 6) {
		while (af.strToInt(objData[6]) != rmNum) {
			objData.erase(objData.begin(), objData.begin() + 7);
			if (objData.size() == 0) {
				break;
			}
		}
		if (objData.size() == 0) {
			break;
		}
		if (objData[0] == "KEY" ||objData[0] == "\nKEY" && objData.size() >= 6) {
			Key* newKey = new Key(objData[1], (objData[2] + objData[3] + objData[4]));
			rmObjs.push_back(newKey);
			rmObjs[rmObjs.size() - 1]->setCorrispondingObject(af.strToInt(objData[5]));
			rmObjs[rmObjs.size() - 1]->setOwned(false);
			objData.erase(objData.begin(), objData.begin() + 7);
		}
		if(objData[0] == "BOOK" || objData[0] == "\nBOOK" && objData.size() >= 6) {
			Book* newKey = new Book(objData[1], (objData[2] + objData[3] + objData[4]));
			rmObjs.push_back(newKey);
			rmObjs[rmObjs.size() - 1]->setCorrispondingObject(af.strToInt(objData[5]));
			rmObjs[rmObjs.size() - 1]->setOwned(false);
			objData.erase(objData.begin(), objData.begin() + 7);
		}

		
	}


	return rmObjs;
}