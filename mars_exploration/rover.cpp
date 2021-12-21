#include "rover.h"





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