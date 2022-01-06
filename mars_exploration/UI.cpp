#include "UI.h"

#include <iostream>
#include <fstream>

using namespace std;

void UI::load(ifstream& file, Queue<Event*>& events /*queue<event> event*/) {// file  ,  takes events list, rovers list to load values from the file to it

	// take pointer and create rovers

	file.open("test.txt");
	int numofeachroverT[3]; //M P E
	float speedofeachroverT[3];//M P E
	int missionsbeforecheckup[3];//M P E
	int checkupduration;
	int AutoP;
	int numofevents;
	for (int i = 0; i < 3; i++) {
		file >> numofeachroverT[i];
	}
	for (int i = 0; i < 3; i++) {
		file >> speedofeachroverT[i];
	}
	for (int i = 0; i < 3; i++) {
		file >> missionsbeforecheckup[i];
	}

	file >> checkupduration;
	file >> AutoP;
	file >> numofevents;


	char eventtype;
	for (int i = 0; i < numofevents; i++) {
		file >> eventtype;

		if(eventtype == 'F'){
			//create a pointer to this type of events and add it to the event enqueue
			int ed, id, mdur,sig;
			float tloc;

			file >> ed >> id >> tloc >> mdur >> sig;

			FormulationEvent* f = new FormulationEvent(eventtype, ed,id,tloc,mdur,sig); //(char MT, int ED, int ID, float TLOC, int MDUR, int SIG)
			events.enqueue(f);  //enqueue //error


		}
		else if (eventtype == 'X'){
			//create a pointer to this type of events and add it to the event enqueue
			int ed, id;
			file >> ed >> id;

			CancelEvent* x = new CancelEvent( ed, id);//, tloc, mdur, sig);
			events.enqueue(x);  //enqueue

		}
		else if (eventtype = 'P'){
			//create a pointer to this type of events and add it to the event queue
			int ed, id;
			file >> ed >> id;

			PromoteEvent* p = new PromoteEvent(ed,id);
			events.enqueue(p);  // enqueue


		}
		else { cout << " the file is corrupted \n"; }

	}

	
	file.close();	
}

void UI::save(ofstream& file, PriorityQueue<mission*> missions /*queue<mission>completed missions*/,int MissionsStat[], int RoversStat[], int TotalWait,int TotalExecution,int TotalPromotion) {
	mission* tempm = new mission();
	file.open("outputfile.txt");
	
	file << "CD  ID  FD  WD  ED  \n";
	int i = 0;
	while (!missions.isEmpty()) {//while the queue is not empty
		missions.dequeue(tempm);

		file  << tempm->getCompletionDay() <<"  "
				<< tempm->getID()<< "  "
				<< tempm->getFormulationDay() <<"  "
				<< tempm->getWaitingDays() <<"  "
				<< tempm->getExecutionDay() <<"  "
				<< endl;
			
	}
	file << "...........................\n";
	file << "...........................\n";
	file << "Missions: " << MissionsStat[0] << "    "
		<< "[M: " << MissionsStat[1] << ", P: "
		<< MissionsStat[2] << ", E: "
		<< MissionsStat[3] << "]"
		<< endl;
	file << "Rover: " << RoversStat[0] << "    "
		<< "[M: " << RoversStat[1] << ", P: "
		<< RoversStat[2] << ", E: "
		<< RoversStat[3] << "]"
		<< endl;

	file << "Avg Wait = " << TotalWait / MissionsStat[0]
		<< ",  Avg Exec = " << TotalExecution / MissionsStat[0]
		<< endl;
	
	file << "Auto-promoted: " << TotalPromotion / MissionsStat[1] //relative to total number of mountain missions only
		<< "%" << endl;




	file.close();




}
