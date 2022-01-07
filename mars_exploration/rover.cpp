#include "rover.h"
#include <iostream> //r




rover::rover(char type, int checkupduration, float speed) {
	setType(type);
	setCheckupDuration(checkupduration);
	setSpeed(speed);

}



void rover::setType(char x) {
	if (x == 'E' || x == 'M' || x == 'P') {
		Type = x;
	}

}
char rover::getType() const {
	return Type;
}

void rover::setCheckupDuration(int x) {
	if (x < 0) { return; }
	CheckupDuration = x;

}
int rover::getCheckupDuration() const {
	return CheckupDuration;
}

void rover::setSpeed(float s) {
	if (s < 0) { return; }
	Speed = s;
}
float rover::getSpeed() const {
	return Speed;
}

void rover::setID(int id) {
	if (id < 0) { return; }
	ID = id;
}
int rover::getID() const {
	return ID;
}


void rover::setMBEforeCheckup(int m) {
	if (m < 0) { return; }
	MBeforeCheckup = m;
}
int rover::getMBEforeCheckup() const {
	return MBeforeCheckup;
}


void rover::setisInCheckup(bool b) {
	isInCheckup = b;
}
bool rover::getisInCheckup() const {
	return MBeforeCheckup;
}




//a
void rover::reset()
{
	ID = -1;
	missionDuration = -1;
	missionOrCheckupEndDay = -1;
	missionLocation = -1;

}

void rover::assignMission(int idMission, int duration, int location, long curDay)
{
	ID = idMission;
	missionDuration = duration;
	missionLocation = location;
	missionOrCheckupEndDay = curDay + missionDuration + ceil((2 * (float(missionLocation / Speed)) / 25.0));

	missionsNumber++;
	if (missionsNumber % CheckupMissions == 0 && missionsNumber >= CheckupMissions)
		needCheckup = true;
	overallDistance += missionLocation;
	if (overallDistance >= 1000 && missionsNumber >= 5)
		needMaintainance = true;
}

void rover::assignCheckup(long curDay)
{
	isInCheckup = true;
	reset();
	missionOrCheckupEndDay = curDay + CheckupDays;
	needCheckup = false;
}

int rover::getMissionOrCheckupEndDay() const
{
	return missionOrCheckupEndDay;
}



//atef 2
bool rover::getneedCheckup() const
{
	return needCheckup;
}

void rover::setOutOfCheckup()
{
	inCheckup = false;
}

bool rover::getneedMaintainance() const
{
	return needMaintainance;
}

void rover::assignMaintainance(int curDay)
{
	reset();
	missionsNumber = 0;
	missionOrCheckupEndDay = curDay + CheckupDays;
	needCheckup = false;
	overallDistance = 0;
	needMaintainance = false;
}



