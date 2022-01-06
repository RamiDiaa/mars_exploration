#pragma once
#include<iostream>
using namespace std;

template<typename P>
class PriorityQueue_Node
{
private:
	int priorityNumber;
	P item;
	PriorityQueue_Node<P>* next;
public:
	PriorityQueue_Node()
	{

	}

	PriorityQueue_Node(P newItem, int prio)
	{
		priorityNumber = prio;
		item = newItem;
		next = nullptr;
	}

	void setItem(P newItem)
	{
		item = newItem;
	}

	P getItem()
	{
		return item;
	}

	void setNext(PriorityQueue_Node<P>* newNext)
	{
		next = newNext;
	}

	PriorityQueue_Node<P>* getNext()
	{
		return next;
	}

	void setPriority(int prio)
	{
		priorityNumber = prio;
	}

	int getPriority()
	{
		return priorityNumber;
	}

	~PriorityQueue_Node()
	{

	}
};

template<typename P>
class PriorityQueue
{
private:
	PriorityQueue<P>* head;
	P item; //r
public:
	PriorityQueue()
	{

	}

	PriorityQueue(PriorityQueue_Node<P>* start)
	{
		head = start;
	}

	bool isEmpty()
	{
		if (head==nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	P peek()
	{
		if (head==nullptr)
		{
			return nullptr;
		}
		return head->getItem();
	}

	void enqueue(P newItem, int prio)
	{
		PriorityQueue_Node<P>* start = head;
		PriorityQueue_Node<P>* temp = new PriorityQueue_Node<P>*(newItem, prio);

		if (head==nullptr)
		{
			head = temp;
		}

		if (head->priorityNumber<prio)
		{
			temp->next = head;
			head = temp;
		}
		else
		{
			while (start->next!=nullptr && start->next->priorityNumber>prio)
			{
				start = start->next;
			}
			temp->next = start->next;
			start->next = temp;
		}
	}

	bool dequeue(P newItem)
	{
		if (head==nullptr)
		{
			return false;
		}
		PriorityQueue_Node<P>* temp = head;
		head = head->next;
		item = temp->item;
		return true;
	}

	void setHead(PriorityQueue_Node<P>* start)
	{
		head = start;
	}

	~PriorityQueue()
	{

	}
};

