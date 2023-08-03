//Sarah Nguyen
//March 06, 2021
//Stack.cpp
//This is the implementation file for the class Stack. This contains all of the functions
//thaat is used in the driver file (hw4.cpp)
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

Stack::Stack()
{
	stackSize = 0;
	maxSize = 25;
	listPtr = new char[maxSize];
	top = -1;
}

Stack::Stack(const Stack& origin)
{
	if (origin.maxSize > 0)
	{
		listPtr = new char[origin.maxSize];
	}
	else
	{
		listPtr = nullptr;
	}
	copy(origin);
}

void Stack::copy(const Stack& orig)
{
    stackSize = orig.stackSize;
    char *temp = new char[stackSize];
	for (int i = 0; i < stackSize; i++)
	{
		temp[i] = orig.listPtr[i];
	}
	top = orig.top;
    destroy();
    listPtr = temp;
}

void Stack::clearStack()
{
	destroy();
	stackSize = 0;
	maxSize = 25;
	listPtr = new char[maxSize];
	top = -1;
}

bool Stack::isPalindrome(Stack& orig)
{
	string firstPal, secondPal;
	for (int i = 0; i < stackSize; i++)
	{
		firstPal += listPtr[i];
	}
	while (!orig.isEmpty())
	{
		secondPal += orig.pop();
	}
    if (firstPal == secondPal)
	{
		clearStack();
		orig.clearStack();
		return true;
	}
	else
	{
		clearStack();
		orig.clearStack();
		return false;
	}
}

char Stack::pop()
{
    char letter;
	if (isEmpty())
	{
		return 0;
	}
	else
	{
        letter = listPtr[top];
        top--;
		stackSize -= 1;
		return letter;
	}

}

void Stack::push(char c)
{
	if (isFull())
	{
		resize();
		push(c);
	}
	else
	{
		top++;
		stackSize++;
		listPtr[top] = c;
	}
}

void Stack::resize()
{
	maxSize = maxSize*2 ;
	char* newArry = new char[maxSize];
	for (int i = 0; i < maxSize; i++)
	{
		newArry[i] = listPtr[i];
	}
	listPtr = newArry;
}

 
void Stack::destroy()
{
	if (stackSize > 0)
	{
		delete[] listPtr;
	}
    listPtr = nullptr;
}

bool Stack::isEmpty()
{
	bool status;
	if (top == -1)
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}

bool Stack::isFull()
{
	bool status;
	if (top == maxSize - 1)
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
}

Stack::~Stack()
{ 
  destroy();
}
