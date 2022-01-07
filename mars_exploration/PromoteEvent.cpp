#include "PromoteEvent.h"

void PromoteEvent::Execute()
{
	auto temp = station->MountainMission.getHead();
	while (temp->getNext())
	{
		if (temp->getItem()->getID() == 1)
		{
			station->MountainMission.removeItem(temp->getItem());
			temp->getItem()->setMissionType('E');
			break;
		}
		temp = temp->getNext();
	}
	station->EmergecnyMissions.enqueue(temp->getItem(), -1 * temp->getItem()->getEndday());
}

//mustafa
