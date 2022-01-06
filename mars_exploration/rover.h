#pragma once




class rover {

private:
	char Type;
	int CheckupDuration;
	float Speed;

	int ID;
	int MBeforeCheckup;
	bool isInCheckup;


	//a
	int CheckupMissions;
	int CheckupDays;
	int overallDistance;


	int missionDuration;
	int missionLocation;
	int missionOrCheckupEndDay;

	int missionsNumber;
	
	bool needCheckup;
	bool inMaintainance;
	bool needMaintainance;



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

	void setisInCheckup(bool);
	bool getisInCheckup() const;


	//a
	void reset();
	void assignMission(int idMission, int duration, int location, long curDay);
	void assignCheckup(long curDay);

	int getMissionOrCheckupEndDay() const;


};










