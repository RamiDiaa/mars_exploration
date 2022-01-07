#pragma once
#include "Event.h"
#include "Station.h"
class PromoteEvent :
    public Event
{

    Station* station; //mustafa
public:
    void Execute();  // (Station* p) removed -- mustafa 
};

