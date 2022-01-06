#pragma once
#include"Mission.h"
class MountainMission :public mission //Mission changes into mission
{
	//there is no data members needed
	int autoPromot;
public:
	MountainMission(int, int, int, int, double, int);
	~MountainMission();
	int getAutoProm();
	bool needAutoProm(int curDay);
};
