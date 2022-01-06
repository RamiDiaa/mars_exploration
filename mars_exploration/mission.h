#pragma once
#include<iostream>
#include"rover.h"

class mission {

private:
	
	char MissionType;
	float TargetLocation;
	int MissionDuration;
	int Significance;

	//int EventDay;
	int ID;
	
	int FormulationDay;
	int WaitingDays;
	int ExecutionDay;
	int CompletionDay;

	//rover* rover;

	//a
	int EndDay;
	rover* assignedRover;

public:
	mission();

	mission(char, int,int,float,int,int, rover*);

	void setID(int);
	int getID()const;

	void setMissionType(char);
	char getMissionType()const;


	void setTargetLocation(float);
	float getTargetLocation()const;


	void setMissionDuration(int);
	int getMissionDuration()const;


	void setsignificance(int);
	int getsignificance()const;




	void setFormulationDay(int);
	int getFormulationDay()const;

	void setCompletionDay(int);
	int getCompletionDay()const;

	void setExecutionDay(int);
	int getExecutionDay()const;

	void setWaitingDays(int);
	int getWaitingDays()const;


	rover* getRover()const;

	//a
	void assignRover(rover*, long);
	int getEndday()const;
};








