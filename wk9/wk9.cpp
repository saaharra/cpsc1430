//Sarah Nguyen
//March 08, 2021
//wk9.cpp
//this is the driver file that tests out the Queue class member functons;
#include <iostream>
#include "Queue.h"
using namespace std;
int main()
{
	Queue myQueue;
	cout << "This is to check if the queue is empty or not: " << endl;
	if (myQueue.isEmpty())
	{
		cout << "This queue is empty" << endl;
	}
	cout << "This is after using enqueue eight times: " << endl;
	myQueue.enqueue(34);
    myQueue.enqueue(231);
    myQueue.enqueue(12);
	myQueue.enqueue(98);
    myQueue.enqueue(23);
    myQueue.enqueue(7);
    myQueue.enqueue(2);
    myQueue.enqueue(8);
	myQueue.display();
	cout << "This is after using dequeue five times: " << endl;
	myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
	myQueue.dequeue();
    myQueue.dequeue();
	myQueue.display();
}
