//Sarah Nguyen
//March 08, 2021
//Queue.cpp
//this is the file that contains all of the functions that is used in hw5.cpp
//this is for the players and their hand
#include <iostream>
#include "Queue.h"
using namespace std;
Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
	numItems = 0;
}

bool Queue::isempty()
{
	bool status;
	if (numItems > 0)
	{
		status = false;
	}
	else
	{
		status = true;
	}
	return status;
}

void Queue::enqueue(int n)
{
	playerQueue* newNode = nullptr;
	newNode = new playerQueue;
	newNode->value = n;
	newNode->next = nullptr;
	if (isempty())
	{
		front = newNode;
		rear = newNode; 
	}
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
	numItems++;
}

int Queue::dequeue()
{
	int num;
	playerQueue* temp = nullptr;
	if (isempty())
	{
		return 0;
	}
	else
	{
		num = front->value;
		temp = front;
		front = front->next;
		delete(temp);
		numItems--;
		return num;
	}
}

int Queue::frontVal()
{
	if (isempty())
	{
		return 0;
	}
	else
	{
		int num = front->value;
		return num;
	}
}

void Queue::destroy()
{
	playerQueue* nodePtr = front;
	while (nodePtr != nullptr)
	{
		playerQueue* temp = nodePtr->next;
		delete nodePtr;
		nodePtr = temp;
	}
	front = nullptr;
	rear = nullptr;
}

void Queue::displayQueue()
{
	playerQueue* listPtr = front;
	while (listPtr)
	{
		cout << listPtr->value << " ";
		listPtr = listPtr->next;
	}
}

Queue::~Queue()
{
    destroy();
}
