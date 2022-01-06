#pragma once
#include<iostream>
using namespace std;

template<typename T>

class Node
{
private:
	T item;
	Node<T>* next;

public:

	Node()
	{

	}

	Node(T newItem)
	{
		next = nullptr;
		item=newItem;
	}

	Node<T>* getNext() const
	{
		return next;
	}

	T getItem() const
	{
		return item;
	}

	void setNext(Node<T>* newNext)
	{
		next = newNext;
	}

	void setItem(T newItem)
	{
		item = newItem;
	}

	~Node()
	{

	}
};

template<typename T>

class LinkedList
{
private:
	Node<T>* head;

public:
	LinkedList()
	{
		head = nullptr;
	}

	bool isEmpty()
	{
		if (head !=NULL)
		{
			return false;
		}
		else
		{
			return true;
		}

	}

	int getLength()
	{
		int c = 0;
		Node<T>* newHead = head;
		while (newHead)
		{
			c=c++;
			newHead = newHead->getNext();
		}
	}

	void insert(T newItem)
	{
		Node<T>* Nhead = new Node<T>(newItem);
		Nhead->setNext(head);
		head = Nhead;
	}

	void remove(Node<T>* Dhead, T Nitem)
	{
		Node<T>* ptr = head;
		Nitem = Dhead->getItem();
		if (head==Dhead)
		{
			head = head->getNext();
		}
		if (Dhead->getNext() == nullptr)
		{
			Node<T>* temp = head;
			while (temp->getNext()!= nullptr)
			{
				temp = temp->getNext();
			}
			temp->setNext(nullptr);
		}
		head = head->getNext();
		Dhead->setItem(ptr->getItem());
	}

	void removeItem(T Ditem)
	{
		Node<T>* temp = head;
		while (temp)
		{
			if (temp->getItem()!=Ditem)
			{
				temp = temp->getNext();
			}
		}
		T item;
		head->remove(temp, item);
	}

	Node<T>* getHead()
	{
		return head;
	}

	~LinkedList()
	{

	}
};