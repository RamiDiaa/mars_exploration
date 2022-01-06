#include "Event.h"

Event::Event(int ED,int mid)
{
	Eventday = ED;
	Missionid = mid;
}

int Event::Geteventday() const
{
	return Eventday;
}

int Event::GetMissionid() const
{
	return Missionid;
}
  

//a
void Event::setStation(Station* ptr)
{
	Mission = ptr;
}