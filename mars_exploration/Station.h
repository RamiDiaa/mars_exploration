#pragma once
#include<iostream>
#include<Windows.h>
#include"Event.h"
#include"rover.h"
#include"mission.h"

#include"LinkedList.h"
#include"Queue.h"
#include"PriorityQueue.h"

#include"UI.h"

//atef 2
#include"CancelEvent.h"
#include"CompletionEvent.h"
//
#include"AutoPromotionEvent.h"
using namespace std;











class Event;
enum ModeOpeartion
{
	Interactive,
	step_by_step,
	silent
};
//








class Station
{
private:
	friend class UI;
	
	Queue<Event*> Events;

	Queue<rover*>EmergencyRovers;
	Queue<rover*>PolarRovers;
	Queue<rover*>MountainRovers;
	PriorityQueue<rover*>RoversINExecution;
	Queue<rover*> EmergencyRoversINCheckup;
	Queue<rover*> PolarRoversINCheckup;
	Queue<rover*> MountainRoversINCheckup;

	
	Queue<mission*>MissionsINExecution;
	PriorityQueue<mission*>MissionsCompleted;

	//atef 2
	LinkedList<mission> WaitingMissions; // atef 2
	LinkedList<rover*>unAvailableMaintainanceEmergency;
	LinkedList<rover*>unAvailableMaintainancePolar;
	LinkedList<rover*>unAvailableMaintainanceMountainous;
	//

	long currentDay=0;

	int EventCount;

	int EmergencyRoversCount;
	int PolarRoversCount;
	int MountainRoversCount;

	int EmergecnyMissionsCount;
	int PolarMissionsCount;
	int MountainMissionsCount;

	//X  int waitingMissions;  X//
	int CheckupDuration;


	ModeOpeartion Mode; //atef 2

	//r
	int MissionsStat[3];
	int RoversStat[3];
	int TotalWait;
	int TotalExecution;
	int TotalPromotion;
	//

public:
	Station();

	//changed to public -- mustafa
	PriorityQueue<mission*>EmergecnyMissions;
	LinkedList<mission*>MountainMission;
	Queue<mission*>PolarMissions;
	
	void simulate(); //atef 2
	
	void execute();





	int getMountMissionCount();
	int getEventCount() const;
	int getEmergencyRoverCount() const;
	int getMountRoverCount() const;
	int getPolRoverCount() const;
	void setEventCount(int count);
	void setEmergencyRoverCount(int count);
	void setMountainRoverCount(int count);
	void setPolarRoverCount(int count);
	
	long getCurrDay();

	bool assignEmergencyMission(int);
	bool assignMountainousMission(int);
	bool assignPolarMission(int);

	void addToCompletedMission();
	void completeRover();// (int) removed --mustafa 
	bool isCompleted(int);


	//atef 2
	int IndexOfMission(const mission& Mission);
	void removeMission(int);

	void addToCompletedMission();
	void completeRover(int);
	bool isCompleted(int);

	//osama
	void PromoteMountainToEmerg(int Missionid);
	//




	~Station();


};

