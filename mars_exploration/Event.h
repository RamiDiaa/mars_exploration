#pragma once
class Event
{
	int Eventday;
	int Missionid;

public:
	Event(int ED, int mid);
	int Geteventday() const;
	int GetMissionid() const;
	virtual void Execute() = 0;
};

