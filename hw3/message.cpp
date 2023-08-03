//Sarah Nguyen
//February 19, 2021
//This is the class file that contains all of the functions that was used in the driver file 
#include <iostream>
#include <string>
#include "message.h"
using namespace std;
hiddenMessage::hiddenMessage(): head(nullptr)
{
 
}

void hiddenMessage::append(string l, int i)
{
	containedMessage* newNode;
	containedMessage* nodePtr;
	newNode = new containedMessage;
	newNode->next = nullptr;
	newNode->index = i;
	newNode->letter = l;
	if (!head)
	{
		head = newNode;
	}
	else
	{
		nodePtr = head;
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;

	}
}

void hiddenMessage::decode()
{
	containedMessage* nodePtr = head;
	int temp;
	string tempname;
	int counter = 0;
	while (nodePtr)
	{
		nodePtr = nodePtr->next;
		counter++;
	}
	nodePtr = head;
	for (int i = 0; i < counter; i++)
	{
		while (nodePtr->next)
		{
			if (nodePtr->index > nodePtr->next->index)
			{
				temp = nodePtr->index;
				nodePtr->index = nodePtr->next->index;
				nodePtr->next->index = temp;
				tempname = nodePtr->letter;
				nodePtr->letter = nodePtr->next->letter;
				nodePtr->next->letter = tempname;
				nodePtr = nodePtr->next;
			}
			else
			{
				nodePtr = nodePtr->next;
			}
		}
		nodePtr = head;
	}
}

void hiddenMessage::display()
{
    containedMessage* nodePtr = head;
	while (nodePtr)
	{
		cout << nodePtr->letter;
		nodePtr = nodePtr->next;
	}
}

void hiddenMessage::destroy()
{
	containedMessage* nodeptr = head;
	containedMessage* nextNode;
	while (nodeptr != nullptr)
	{
		nextNode = nodeptr->next;
		delete nodeptr;
		nodeptr = nextNode;
	}
	head = nullptr;
}

hiddenMessage::~hiddenMessage()
{
    destroy();
}
