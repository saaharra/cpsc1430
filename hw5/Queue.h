//Sarah Nguyen
//March 08, 2021
//Queue.h
//This is the header file that contains the definition for the functions that are
//written and contained in Queue.cpp
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
class Queue
{
public:
	Queue();
    ~Queue();
    //PRE: this takes in the queue 
    //POST: pushes in the number to the front of the queue;
    void enqueue(int);
    //PRE: this takes in the queue
    //POST: this returns whether or not the linked list is empty 
    bool isempty();
    //PRE: takes in the queue
    //POST: this takes off the front of the queue and returns its value
    int dequeue();
    //PRE: this takes in the queue
    //POST: this returns the front value of the queue
    int frontVal();
    //PRE: this takes in the queue
    //POST: none, but the purpose is to print out the queue
	void displayQueue();
private:
	struct playerQueue
	{
		int value;
		playerQueue* next;
	};
	playerQueue* front;
	playerQueue* rear;
    int numItems;
    //PRE: this takes in the queue and destroys it
    //POST: this goes through the queue and deletes the memory there, sets the front and end to nullptr
	void destroy();
};
#endif // !QUEUE_H
