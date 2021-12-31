#include "FormulationEvent.h"

FormulationEvent::FormulationEvent(char MT, int ED, int ID, float TLOC, int MDUR, int SIG)
    :Event(ED, ID)
{
    MissionType = MT;
    MissionTargetLocation = TLOC;
    noofdaysinTarget = MDUR;
    MissionSIG = SIG;

}

int FormulationEvent::GetMissionType() const
{
    return MissionType;
}
int FormulationEvent::GetMissionTargetLocation() const
{
    return MissionTargetLocation;
}
int FormulationEvent::GetnoofdaysinTarget() const
{
    return noofdaysinTarget;
}
int FormulationEvent::GetMissionSIG() const
{
    return MissionSIG;
}

void FormulationEvent::Execute()       //is that right or i should declare excute function in Formulationevent.h then use formulationevent before resolution scope instead of event
{

}