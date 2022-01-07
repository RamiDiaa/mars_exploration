#pragma once


//a
#include"LinkedList.h"
#include"Queue.h"
#include"PriorityQueue.h"
//#include "Station.h" //mustafa

class Station;
//

class Event
{
	int Eventday;
	int Missionid;
protected:
	Station* station; //a Mission // m
public:
	Event(int ED, int mid);
	int Geteventday() const;
	int GetMissionid() const;
	virtual void Execute(Station *p) = 0;

	void setStation(Station* ptr); //a
};



