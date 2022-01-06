#pragma once


//a
#include"LinkedList.h"
#include"Queue.h"
#include"PriorityQueue.h"

class Station;
//

class Event
{
	int Eventday;
	int Missionid;
protected:
	Station* Mission; //a
public:
	Event(int ED, int mid);
	int Geteventday() const;
	int GetMissionid() const;
	virtual void Execute() = 0;

	void setStation(Station* ptr); //a
};

