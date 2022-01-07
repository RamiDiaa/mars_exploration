#include"CompletionEvent.h"

CompletionEvent::CompletionEvent(int eV,int mid) :Event(eV,mid)
{

}

CompletionEvent::~CompletionEvent()
{
}

void CompletionEvent::execute(Station* m)
{
	while (m->isCompleted(Geteventday()))
	{
		m->addToCompletedMission();
	}
	m->completeRover(Geteventday());
}