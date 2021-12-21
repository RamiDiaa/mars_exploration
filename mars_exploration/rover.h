#pragma once




class rover {

private:
	char Type;
	int CheckupDuration;
	float Speed;

	int ID;
	int MBeforeCheckup;


public:
	rover(char type,int checkupduration, float speed);

	void setType(char);
	char getType() const;
	
	void setCheckupDuration(int);
	int getCheckupDuration() const;

	void setSpeed(float);
	float getSpeed() const;

	void setID(int);
	int getID() const;

	void setMBEforeCheckup(int);
	int getMBEforeCheckup() const;

};










