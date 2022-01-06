#pragma once
#include"Event.h"
#include"Station.h"
class AutoPromotionEvent :public Event
{
public:
	AutoPromotionEvent(int);
	void execute(Station* mStation); //marsstaion* changed to station*

	~AutoPromotionEvent();
};