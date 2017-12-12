#include "stdafx.h"
#include "MotionTableEntry.h"
#include <memory>

MotionTableEntry::MotionTableEntry() {

}

 MotionTableEntry::MotionTableEntry(int atttachedRm, int rmNumN, int rmNumS, int rmNumE, int rmNumW, vector<Door*> doors) {
	 setConnectingRoomN(rmNumN);
	 setConnectingRoomS(rmNumS);
	 setConnectingRoomE(rmNumE);
	 setConnectingRoomW(rmNumW);
	 setAttachedRoom(atttachedRm);
	 this->doors = doors;
}

 int MotionTableEntry::getConnectingRoomN() {
	 return rmConnectedN;
 }

 void MotionTableEntry::setConnectingRoomN(int rm) {
	 rmConnectedN = rm;
 }

 int MotionTableEntry::getConnectingRoomS() {
	 return rmConnectedS;
 }

 void MotionTableEntry::setConnectingRoomS(int rm) {
	 rmConnectedS = rm;
 }

 int MotionTableEntry::getConnectingRoomE() {
	 return rmConnectedE;
 }

 void MotionTableEntry::setConnectingRoomE(int rm) {
	 rmConnectedE = rm;
 }

 int MotionTableEntry::getConnectingRoomW() {
	 return rmConnectedW;
 }

 void MotionTableEntry::setConnectingRoomW(int rm) {
	 rmConnectedW = rm;
 }

 int MotionTableEntry::getAttachedRoom() {
	 return rmNum;
 }

 void MotionTableEntry::setAttachedRoom(int rm) {
	 rmNum = rm;
 }

 vector<Door*> MotionTableEntry::getDoors() {
	 return doors;
 }
