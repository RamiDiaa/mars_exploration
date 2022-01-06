#include "AutoPromotionEvent.h"

AutoPromotionEvent::AutoPromotionEvent(int ed) :Event(ed)
{
}

void AutoPromotionEvent::execute(Station* mStation)
{
	mStation->promoteMountainousToEmergencyMission(Geteventday());

}

AutoPromotionEvent::~AutoPromotionEvent()
{
}