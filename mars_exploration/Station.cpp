#include"Station.h"

Station::Station()
{
	EventCount = 0;
	MountainRoversCount = 0;
	EmergencyRoversCount = 0;
	PolarRoversCount = 0;
	MountainMissionsCount = 0;
	EmergecnyMissionsCount = 0;
	PolarMissionsCount = 0;
	//waitingMissions = 0;
	CheckupDuration = 0;


	//r 
	//for stats
	for (int i; i < 3; i++) {
		MissionsStat[i] =0;
		RoversStat[i] = 0 ;
	}
	TotalWait = 0;
	TotalExecution=0;
	TotalPromotion=0;
	//
}

int Station::getMountMissionCount()
{
	return MountainMissionsCount;
}

int Station::getEventCount() const
{
	return EventCount;
}

int Station:: getEmergencyRoverCount() const
{
	return EmergencyRoversCount;
}

int Station::getMountRoverCount() const
{
	return MountainRoversCount;
}

int Station :: getPolRoverCount() const
{
	return PolarRoversCount;
}

void Station::setEventCount(int count)
{
	EventCount = count;
}

void Station::setEmergencyRoverCount(int count)
{
	EmergencyRoversCount = count;
}

void Station::setMountainRoverCount(int count)
{
	MountainRoversCount = count;
}

void Station::setPolarRoverCount(int count)
{
	PolarRoversCount = count;
}

long Station::getCurrDay()
{
	return currentDay;
}


//atef 2///////////////////////////

void Station::simulate()   //add this 
{
	//rami
	UI ui;
	ifstream inputfile;
	inputfile.open("TEST.txt");
	ui.load(inputfile, Events, RoversStat);
//////////





	// osama
	Event* p = nullptr;
	while (Events.peek()->Geteventday() == currentDay || Events.peek()->Geteventday() < currentDay)
	{
		Events.dequeue(p);
		p->Execute(this);
	}





	UI* uiPtr = new UI(this);
	AutoPromotionEvent* autoPromotion;
	Assign* assignEvent;
	CompletionEvent* completionEvent;
	bool status;
	Event* tempEvent;
	if (Events.isEmpty())
	{
		switch (Mode)
		{
		case Interactive:
			uiPtr->printDay();
			cin.get();
			break;
		case step_by_step:
			uiPtr->printDay();
			Sleep(1500);
			break;
		case silent:
			uiPtr->printSilent();
			break;
		}
		uiPtr->outputFile();
		return;
	}

	Events.peek(tempEvent);
	currentDay = tempEvent->Geteventday();
	bool increment = false;
	cin.get();
	do
	{
		if (Events.peek(tempEvent))
		{
			if (tempEvent->Geteventday() <= currentDay)
			{
				tempEvent->Execute();
				Events.dequeue(tempEvent);
				increment = false;
			}
			else
				increment = true;
		}
		else
			increment = true;

		autoPromotion = new AutoPromotionEvent(currentDay);
		assignEvent = new Assign(currentDay);
		completionEvent = new CompletionEvent(currentDay);
		autoPromotion->execute(this);
		completionEvent->execute(this);
		assignEvent->execute(this);

		switch (Mode)
		{
		case Interactive:
			if (increment)
			{
				uiPtr->printDay();
				cin.get();
			}
			break;
		case step_by_step:
			if (increment)
			{
				uiPtr->printDay();
				Sleep(1500);
			}
			break;
		case silent:
			break;
		}
		if (increment)
			currentDay++;
		if (currentDay == 25)
			cout << "" << endl;
		//eventList.dequeue(tempEvent);
		status = !WaitingMissions.isEmpty() || !Events.isEmpty() || !MissionsINExecution.isEmpty() || !RoversINExecution.isEmpty();
		delete autoPromotion; delete assignEvent; delete completionEvent;
	} while (status);
	if (Mode == silent)
		uiPtr->printSilent();
	uiPtr->outputFile();



	//rami

	ofstream outputfile;
	outputfile.open("OutputFile.txt");
	ui.save(outputfile, MissionsCompleted, MissionsStat, RoversStat, TotalWait, TotalExecution, TotalPromotion);
//////////////
}

bool Station::assignPolarMission(int eventDay) ///add this 
{

	//rami
	MissionsStat[1] ++;
	//

	mission* pMissionTemp;
	if (!PolarMissions.peek(pMissionTemp))
		return false;

	rover* pRoverTemp;
	if (PolarRovers.dequeue(pRoverTemp))
	{
		PolarMissions.dequeue(pMissionTemp);
		pRoverTemp->assignMission(pMissionTemp->getMissionType(), pMissionTemp->getMissionDuration(), pMissionTemp->getTargetLocation(), eventDay);
		pMissionTemp->assignRover(pRoverTemp, currentDay);
		MissionsINExecution.enqueue(pMissionTemp);

		RoversINExecution.enqueue(pRoverTemp, -1 * pMissionTemp->getEndday());
		return true;
	}
	rover* generalTemp;
	if (!unAvailableMaintainancePolar.isEmpty())
	{
		PolarMissions.dequeue(pMissionTemp);
		generalTemp->assignMission(pMissionTemp->getMissionType(), pMissionTemp->getMissionDuration(), pMissionTemp->getTargetLocation(), eventDay);
		pMissionTemp->assignRover(generalTemp, currentDay);
		MissionsINExecution.enqueue(pMissionTemp);
		RoversINExecution.enqueue(generalTemp, -1 * pMissionTemp->getEndday());
		return true;
	}

	return false;
}


void Station::completeRover(int endDay) ///add this
{
	rover* rV;
	bool Found = RoversINExecution.peek(rV);
	while (Found && rV->getMissionOrCheckupEndDay() == endDay)
	{
		RoversINExecution.dequeue(rV);
		if (rV->getneedCheckup())
		{
			rV->assignCheckup(endDay);
			RoversINExecution.enqueue(rV, -1 * rV->getMissionOrCheckupEndDay());
		}
		else
		{
			rV->setOutOfCheckup();
			rover* eR = dynamic_cast<rover*>(rV);
			rover* mR = dynamic_cast<rover*>(rV);
			rover* pR = dynamic_cast<rover*>(rV);
			if (rV->getneedMaintainance())
			{
				rV->assignMaintainance(endDay);
				if (eR)
					unAvailableMaintainanceEmergency.insert(eR);
				else if (mR)
					unAvailableMaintainanceMountainous.insert(mR);
				else
					unAvailableMaintainancePolar.insert(pR);

			}
			else
			{
				if (eR)
					EmergencyRovers.enqueue(eR);
				else if (mR)
					MountainRovers.enqueue(mR);
				else if (pR)
					PolarRovers.enqueue(pR);

				rV->setOutOfCheckup();
			}

		}
		Found = RoversINExecution.peek(rV);
	}
}

bool Station::isCompleted(int eD) //ADD
{
	mission* mTemp = nullptr;
	bool Found = MissionsINExecution.peek(mTemp);
	if (Found && mTemp->getEndday() <= eD)
		return true;
	return false;
}


/////////////////////////


//atef 2/////////////////////
int Station::IndexOfMission(const mission& mMission)
{
	return WaitingMissions.getIndexOf(mMission);
}

void Station::removeMission(int index)
{
	WaitingMissions.remove();
}
//////////////////////////
///mustafa//////////
bool Station::assignMountainousMission(int eventDay)
{
	//rami
	MissionsStat[0] ++;
 	//
	if (!MountainMission.getHead())
		return false;
	mission* pMissionTemp;
	rover* tempRover;
	if (MountainRovers.dequeue(tempRover))
	{
		pMissionTemp = MountainMission.getHead()->getItem();
		MountainMission.removeItem(pMissionTemp);

		tempRover->assignMission(pMissionTemp->getMissionType(), pMissionTemp->getMissionDuration(),
			pMissionTemp->getTargetLocation(), eventDay);

		pMissionTemp->assignRover(tempRover, currentDay);

		RoversINExecution.enqueue(tempRover, -1 * pMissionTemp->getEndday());
		return true;
	}
	if (EmergencyRovers.dequeue(tempRover))
	{
		pMissionTemp = MountainMission.getHead()->getItem();
		MountainMission.removeItem(pMissionTemp);

		tempRover->assignMission(pMissionTemp->getMissionType(), pMissionTemp->getMissionDuration(),
			pMissionTemp->getTargetLocation(), eventDay);
		pMissionTemp->assignRover(tempRover, currentDay);

		RoversINExecution.enqueue(tempRover, -1 * pMissionTemp->getEndday());
		return true;
	}
	return false; //Assign to waiting
}
void Station::completeRover()
{
	auto temp = RoversINCheckup.getHead();
	while (temp->getNext())
	{
		if (temp->getItem()->getCheckupDuration() == temp->getItem()->getCheckupDays())
		{
			RoversINCheckup.removeItem(temp->getItem());
			temp->getItem()->resetCheckupDays();
			char c = temp->getItem()->getType();
			if (c == 'E')
				EmergencyRovers.enqueue(temp->getItem());
			else if (c == 'M')
				MountainRovers.enqueue(temp->getItem());
			else
				PolarRovers.enqueue(temp->getItem());
		}
		else
		{
			temp->getItem()->incrementCheckupDays();
		}
	}
}



///////////////




/*
bool Station ::assignPolarMission(int eventDay)
{
	mission* pMissionTemp;
	if (!PolarMissions.peek())
		return false;  

	rover* pRoverTemp;
	if (PolarRovers.dequeue(pRoverTemp))
	{
		PolarMissions.dequeue(pMissionTemp);
		pRoverTemp->assignMission(pMissionTemp->getMissionType(), pMissionTemp->getMissionDuration(), pMissionTemp->getTargetLocation(), eventDay);
		pMissionTemp->assignRover(pRoverTemp, currentDay);
		MissionsINExecution.enqueue(pMissionTemp);

		RoversINExecution.enqueue(pRoverTemp, -1 * pMissionTemp->getEndday());
		return true;
	}

}
*/










//osama ////////////////////////////////
bool Station::assignEmergencyMission(int)
{
	//rami
	MissionsStat[2] ++;
	//


	bool w = false;
	if (!EmergecnyMissions.peek())
		return false;
	mission* p = nullptr;
	rover* r = nullptr;
	while (!EmergecnyMissions.isEmpty())
	{
		if (!EmergencyRovers.isEmpty())
		{

			EmergecnyMissions.dequeue(p);
			EmergencyRovers.dequeue(r);
			r->assignMission(p->getID(), p->getMissionDuration(), p->getTargetLocation(), currentDay);
			p->assignRover(r, currentDay);
			MissionsINExecution.enqueue(p);
			RoversINExecution.enqueue(r, -1 * p->getEndday());
			w = true;
		}

		else if (!MountainRovers.isEmpty())
		{

			EmergecnyMissions.dequeue(p);
			MountainRovers.dequeue(r);
			r->assignMission(p->getID(), p->getMissionDuration(), p->getTargetLocation(), currentDay);
			p->assignRover(r, currentDay);
			MissionsINExecution.enqueue(p);
			RoversINExecution.enqueue(r, -1 * p->getEndday());
			w = true;
		}
		else if (!PolarRovers.isEmpty())
		{

			EmergecnyMissions.dequeue(p);
			PolarRovers.dequeue(r);
			r->assignMission(p->getID(), p->getMissionDuration(), p->getTargetLocation(), currentDay);
			p->assignRover(r, currentDay);
			MissionsINExecution.enqueue(p);
			RoversINExecution.enqueue(r, -1 * p->getEndday());
			w = true;
		}
		else
			break;

	}

	return w;

}




void Station::PromoteMountainToEmerg(int Missionid)
{

	Node<mission*>* p = MountainMission.getHead();

	if (p->getItem()->getID() == Missionid)
	{
		p->getItem()->setMissionType('E');
		EmergecnyMissions.enqueue(p->getItem(), 0);
		MountainMission.removeItem(p->getItem());
	}


	while (p->getNext())
	{
		if (p->getNext()->getItem()->getID() == Missionid)
		{
			p->getNext()->getItem()->setMissionType('E');
			EmergecnyMissions.enqueue(p->getNext()->getItem(), 0);   //priority euqation value instead of 0

			p->setNext(p->getNext()->getNext());
			MountainMission.removeItem(p->getNext()->getItem());
			break;
		}

		p = p->getNext();
	}
}




	

// ////////// /


void Station::execute()
{
	UI ui;
	ifstream inputfile;
	inputfile.open("TEST.txt");
	ui.load(inputfile, Events ,RoversStat);
	

	

	// osama
	Event* p = nullptr;
	while (Events.peek()->Geteventday() == currentDay || Events.peek()->Geteventday() < currentDay)
	{
		Events.dequeue(p);
		p->Execute(this);
	}
	/////
	


	ofstream outputfile;
	outputfile.open("OutputFile.txt");
	ui.save(outputfile, MissionsCompleted, MissionsStat, RoversStat, TotalWait, TotalExecution, TotalPromotion);
}




Station::~Station()
{

}



