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
using namespace std;


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

	PriorityQueue<mission*>EmergecnyMissions;
	Queue<mission*>PolarMissions;
	LinkedList<mission*>MountainMission;
	Queue<mission*>MissionsINExecution;
	PriorityQueue<mission*>MissionsCompleted;

	long currentDay=0;

	int EventCount;

	int EmergencyRoversCount;
	int PolarRoversCount;
	int MountainRoversCount;

	int EmergecnyMissionsCount;
	int PolarMissionsCount;
	int MountainMissionsCount;

	int waitingMissions;
	int CheckupDuration;


	//r
	int MissionsStat[3];
	int RoversStat[3];
	int TotalWait;
	int TotalExecution;
	int TotalPromotion;
	//

public:
	Station();

	
	
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
	void completeRover(int);
	bool isCompleted(int);

	~Station();


};

