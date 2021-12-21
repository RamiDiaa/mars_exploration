#pragma once


class mission {

private:
	int FormulationDay;
	char MissionType;
	float TargetLocation;
	int MissionDuration;
	int significance;

	int EventDay;
	int ID;

	int WaitingDays;
	int ExecutionDay;

public:
	mission(char mtype, int eday, int id, float tloc,int sig);

	void setFormulationDay();
	int getFormulaitonDay()const;


	void setMissionType();
	char getMissionType()const;


	void setTargetLocation();
	float getTargetLocation()const;


	void setMissionDuration();
	int getMissionDuration()const;


	void setsignificance();
	int getsignificance()const;


};








