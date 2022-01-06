#include"MountainMission.h"

MountainMission::MountainMission(int fD, int tL, int mD, int iD, double sig, int autoProm) :mission(fD, tL, mD, iD, sig), autoPromot(autoProm) 
{}

MountainMission::~MountainMission()
{
}

int MountainMission::getAutoProm()
{
	return autoPromot;
}

bool MountainMission::needAutoProm(int curDay)
{
	return (autoPromot <= (curDay - getFormulationDay()));
}