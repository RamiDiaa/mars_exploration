#pragma once
#include "Event.h"
#include"Station.h"

class CancelEvent : public Event
{
private:
    int ID;

public:

    CancelEvent(int day, int id);
    void Execute(Station* marsStation);
    ~CancelEvent();

};

