#include "mission.h"




mission::mission(){}
mission::mission(char mtype,int id, int eday, float tloc,int mdur , int sig =0, rover* rover =nullptr) { // rover*) changed to rover* rover = nullptr)
	MissionType = mtype;
	ID = id;
	ExecutionDay = eday;
	TargetLocation = tloc;
	MissionDuration = mdur;
	Significance = sig;
	assignedRover = nullptr;
}


void mission::setID(int i) {
	ID = i;
}
int mission::getID()const {
	return ID;
}



void mission::setMissionType(char mt) {
	MissionType = mt;
}
char mission::getMissionType()const {
	return MissionType;
}


void mission::setTargetLocation(float tl) {
	TargetLocation = tl;

}
float mission::getTargetLocation()const {
	return TargetLocation;
}


void mission::setMissionDuration(int md) {
	MissionDuration = md;
}
int mission::getMissionDuration()const {
	return MissionDuration;
}


void mission::setsignificance(int s) {
	Significance = s;

}
int mission::getsignificance()const {
	return Significance;
}

void mission::setFormulationDay(int fd) {
	FormulationDay = fd;
}
int mission::getFormulationDay()const {
	return FormulationDay;
}

void mission::setCompletionDay(int cd) {
	CompletionDay = cd;
}
int mission::getCompletionDay()const {
	return CompletionDay;
}

void mission::setExecutionDay(int ed) {
	ExecutionDay = ed;
}
int mission::getExecutionDay()const {
	return ExecutionDay;
}

void mission::setWaitingDays(int wd) {
	WaitingDays = wd;
}
int mission::getWaitingDays()const {
	return WaitingDays;
}

rover* mission::getRover()const {
	return assignedRover;
}

//a

int mission::getEndday() const
{
	return EndDay;
}

void mission::assignRover(rover* rV, long curDay)
{
	assignedRover = rV;
	ExecutionDay = curDay;
	EndDay = rV->getMissionOrCheckupEndDay();
}






