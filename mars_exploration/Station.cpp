#include"Station.h"

Station::Station()
{
	EventCount = 0;
	MountainRoversCount = 0;
	EmergencyRoversCount = 0;
	PolarRoversCount = 0;
	MountainMissionsCount = 0;
	EmergecnyMissionsCount = 0;
	PolarMissionsCount = 0;
	waitingMissions = 0;
	CheckupDuration = 0;
}

int Station::getMountMissionCount()
{
	return MountainMissionsCount;
}

int Station::getEventCount() const
{
	return EventCount;
}

int Station:: getEmergencyRoverCount() const
{
	return EmergencyRoversCount;
}

int Station::getMountRoverCount() const
{
	return MountainRoversCount;
}

int Station :: getPolRoverCount() const
{
	return PolarRoversCount;
}

void Station::setEventCount(int count)
{
	EventCount = count;
}

void Station::setEmergencyRoverCount(int count)
{
	EmergencyRoversCount = count;
}

void Station::setMountainRoverCount(int count)
{
	MountainRoversCount = count;
}

void Station::setPolarRoverCount(int count)
{
	PolarRoversCount = count;
}

long Station::getCurrDay()
{
	return currentDay;
}

bool Station ::assignPolarMission(int eventDay)
{
	mission* pMissionTemp;
	if (!PolarMissions.peek())
		return false;  

	rover* pRoverTemp;
	if (PolarRovers.dequeue(pRoverTemp))
	{
		PolarMissions.dequeue(pMissionTemp);
		pRoverTemp->assignMission(pMissionTemp->getMissionType(), pMissionTemp->getMissionDuration(), pMissionTemp->getTargetLocation(), eventDay);
		pMissionTemp->assignRover(pRoverTemp, currentDay);
		MissionsINExecution.enqueue(pMissionTemp);

		RoversINExecution.enqueue(pRoverTemp, -1 * pMissionTemp->getEndday());
		return true;
	}

}

Station::~Station()
{

}