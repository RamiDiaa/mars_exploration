#pragma once
#include "Event.h"
class FormulationEvent :
    public Event
{
    char MissionType;
    float MissionTargetLocation;
    int noofdaysinTarget;
    int MissionSIG;

public:

    FormulationEvent(char MT, int ED, int ID, float TLOC, int MDUR, int SIG);
    int GetMissionType() const;
    int GetMissionTargetLocation() const;
    int GetnoofdaysinTarget() const;
    int GetMissionSIG() const;
    void Execute();


     

};

