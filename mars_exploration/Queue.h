#pragma once

#include<iostream>
using namespace std;

template<typename E>
class Queue_Node
{
private:
	E item;
	Queue_Node<E>* next;


public:
	Queue_Node()
	{

	}

	Queue_Node(E newItem)
	{
		next = nullptr;
		item = newItem;
	}

	void setNext(Queue_Node<E>* newNext)
	{
		next = newNext;
	}

	Queue_Node<E>* getNext()
	{
		return next;
	}

	void setItem(E newItem)
	{
		item = newItem;
	}

	E getItem()
	{
		return item;
	}

	~Queue_Node()
	{

	}
};

template<typename E>
class Queue
{
private:
	Queue_Node<E>* front;
	Queue_Node<E>* rear;

public:
	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}

	bool isEmpty()
	{
		if (front==nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void enqueue(E item)
	{
		Queue_Node<E>* temp = new Queue_Node<E>*(item);
		if (!rear)
		{
			front = temp;
			rear = temp;
		}
		else
		{
			rear->setNext(temp);
			rear = temp;
		}
	}

	bool dequeue(E& head)
	{
		if (front==nullptr)
		{
			return false;
		}
		else
		{
			Queue_Node<E>* temp = front;
			head = temp->getItem();
			front = front->getNext();
			if (front==nullptr)
			{
				rear = nullptr;
			}
			return true;
		}
	}

	E peek()
	{
		if (front==nullptr)
		{
			return nullptr;
		}

		return front->getItem();
	
	}

	~Queue()
	{

	}
};

