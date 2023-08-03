//Sarah Nguyen
//March 08, 2021
//Program: this is the implementation file and contains the functions that is used
//in the wk9.cpp driver file.
#include <iostream>
#include "Queue.h"
using namespace std;

//this is the constructor
Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
	numItems = 0;
}

//this function adds something to the rear of the queues
void Queue::enqueue(int num)
{
	queueNode* newNode = nullptr;
	newNode = new queueNode;
	newNode->value = num;
	newNode->next = nullptr;
	if (isEmpty())
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

//a function to dsiplay the Queue 
void Queue::display()
{
	queueNode* temp = front;
	while (temp)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
}
//this is the function that removes the front and returns the value
int Queue::dequeue()
{
	int num;
	queueNode* temp = front;
    //this checks if the queue is empty, if so, then it ends the function
	if (isEmpty())
	{
		return 0;
	}
    //else go through and retrieve the data and delete it and return the first value
	else
	{
		num = front->value;
		front = front->next;
        if(front)
          {
            rear = nullptr;
          }
        numItems -=1;
		delete(temp);
		return num;
	}
}
//this checks if the queue is empty or not
bool Queue::isEmpty()
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

//this is the desctructor
Queue::~Queue()
{
    queueNode* nodePtr = front;
    queueNode* temp;
	while (nodePtr!=nullptr)
	{
		temp = nodePtr->next;
		delete nodePtr;
		nodePtr = temp;
	}
	front = nullptr;
    rear = nullptr;
}
