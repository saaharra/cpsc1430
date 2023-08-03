//Sarah Nguyen
//March 08, 2021
//Stack.cpp
//This is the stack member functions that contains the array of values for the
//game that is played in the driver file, hw5.cpp
#include <iostream>
#include "Stack.h"
using namespace std;
//this is the constructor
Stack::Stack()
{
	stackSize = 0;
	arrySize = 52;
	cardArry = new int[arrySize];
	top = -1;
}
void Stack::destroy()
{
	if (stackSize > 0)
	{
		delete[] cardArry;
	}
	cardArry = nullptr;
}

void Stack::push(int n)
{
	if (isFull())
	{
		resize();
		push(n);
	}
	else
	{
		top++;
		stackSize++;
		cardArry[top] = n;
	}
}

int Stack::peek()
{
	if (isEmpty())
	{
		return 0;
	}
	return cardArry[top];
}

int Stack::pop()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		top--;
		stackSize -= 1;
		return cardArry[top];
	}
}

void Stack::resize()
{
	arrySize *= 2;
	int* temp = new int[arrySize];
	for (int i = 0; i < arrySize; i++)
	{
		temp[i] = cardArry[i];
	}
	destroy();
	cardArry = temp;
}

void Stack::displayStack()
{
	for (int i = 0; i >= 0; i--)
	{
		cout << cardArry[i] << " ";
	}
	cout << endl;
}

bool Stack::isFull()
{
	bool status;
	if (top == arrySize - 1)
	{
		status = true;
	}
	else
	{
		status = false;
	}
	return status;
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

bool Stack::oneCard()
{
	if (top > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int Stack::getSize()
{
	int size = 0;
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < stackSize; i++)
		{
			size++;
		}
	}
	return size;
}

Stack::~Stack()
{
  destroy();
}
