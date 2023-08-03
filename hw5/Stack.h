//Sarah Nguyen
//March 08, 2021
//Stack.h
//This is the headerfile that contains all of the definitions for the member funtions
//that is held within Stack.cpp
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
class Stack
{
public:
	Stack();
    ~Stack();
    //PRE: this takes in the stack
    //POST: this takes off the top of the stack and returns its value
    int pop();
    //PRE: this takes in the stack and adds a value to it
    //POST: this returns the stack with a new value added to the front of it
    void push(int);
    //PRE: this takes in the stack and looks at if its full or not
    //POST: this returns the status on whether or not it is full or not
    bool isFull();
    //PRE: this takes in the stack and looks at if its empty or not
    //POST: this returns the status on whether or not it is empty or not
    bool isEmpty();
    //PRE: this takes in the stack and makes a temp copy of it of a bigger array size and copies the data into the temp, then sets the two together
    //POST: this returns a stack with a new size
    void resize();
    //this was used moreso for testing and seeing what the stacks held
    //PRE: this takes in the stack and prints out the values
    //POST: there is no post condition, the purpose is to print out the stack
    void displayStack();
    //PRE: this takes in the stack
    //POST: returns the top value of the stack
    int peek();
    //PRE: this takes in the stack and looks for the size 
    //POST: this returns the size of the stack
    int getSize();
    //PRE: looks at a stack and checks how many cards are left in it
    //POST: returns whether or not there is one card left in the stack
    bool oneCard();
private:
	int* cardArry;
	int arrySize;
	int stackSize;
    int top;
    //PRE: this takes in the stack and deletes the memory there
    //PRE: sets the arry to nullptr
	void destroy();
};
#endif // !STACK_H
