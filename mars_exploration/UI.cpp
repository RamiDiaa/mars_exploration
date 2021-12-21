#include "UI.h"
#include <iostream>
#include <fstream>
using namespace std;

void UI::load(ifstream file, int event[] /*queue<event> event*/) {// file  ,  takes events list, rovers list to load values from the file to it

	// take pointer and create rovers

	file.open("test.txt");
	int numofeachrover[3]; //M P E
	float speedofeachrover[3];//M P E
	int missionbeforecheckup[3];//M P E
	int checkupduration;
	int AutoP;
	int numofevents;
	for (int i = 0; i < 3; i++) {
		file >> numofeachrover[i];
	}
	
	file >> checkupduration;

	for (int i = 0; i < 3; i++) {
		file >> speedofeachrover[i];
	}

	file >> AutoP;
	file >> numofevents;



	for (int i = 0; i < numofevents; i++) {

	}


	file.close();	
}

