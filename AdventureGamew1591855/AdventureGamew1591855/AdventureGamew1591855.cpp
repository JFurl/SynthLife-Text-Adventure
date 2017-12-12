// AdventureGamew1591855.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include "AdventureGame.h"
#include "AdditionalFunctions.h"
using namespace std;

int main()
{
	SetConsoleTitle(TEXT("ADVENTURE"));
	ifstream inFile;
	ofstream outFile;
	int choice = 0;
	AdventureGame Game;
	
	while (choice != 3) {
		Game.mainMenuLoop(inFile, outFile);
	}
	
	

    return 0;
}

