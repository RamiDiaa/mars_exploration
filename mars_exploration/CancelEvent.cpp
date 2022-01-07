#include "CancelEvent.h"

CancelEvent::CancelEvent(int day, int id) : Event(day, id)
{
}



void CancelEvent::Execute(Station* marsStation)
{
	mission Mission(0, 0, 0, ID, 0, 0, nullptr);
	int MissionIndex = marsStation->IndexOfMission(Mission);
	if (MissionIndex != -1)
	{
		marsStation->removeMission(MissionIndex);
	}
}

CancelEvent::~CancelEvent()
{

}