#pragma once
#include"Event.h"
#include"Station.h"

class CompletionEvent :public Event
{

public:

	CompletionEvent(int, int);
	~CompletionEvent();
	void execute(Station*);

};