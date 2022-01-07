#include "AutoPromotionEvent.h"


AutoPromotionEvent::AutoPromotionEvent(int ed, int mid) :Event(ed, mid)
{
}

void AutoPromotionEvent::execute(Station* mStation)
{
	auto temp = mStation->MountainMission.getHead();
	while (temp->getNext())
	{
		if (temp->getItem()->getID() == GetMissionid())
		{
			mStation->MountainMission.removeItem(temp->getItem());
			temp->getItem()->setMissionType('E');
			break;
		}
		temp = temp->getNext();
	}
	mStation->EmergecnyMissions.enqueue(temp->getItem(), -1 * temp->getItem()->getEndday());

}

AutoPromotionEvent::~AutoPromotionEvent()
{
}

//mustafa