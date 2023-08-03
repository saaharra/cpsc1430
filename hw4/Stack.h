//Sarah Nguyen
//March 06, 2021
//Stack.h
//this is the header file for all of the functions that is contained in the Stack.cpp

#include <string>
#ifndef STACK_H
#define STACK_H
class Stack
{
public:
    //this is in the constructor
    //PRE: none
    //POST: puts out an empty stack array
	Stack();  
    //this is in the desctructor
    //PRE: this just deletes the stack
    //POST: an empty stack and listPtr is set to nullptr
	~Stack();
    //this is in the copy contructor
    //PRE: this takes in the original stack array and then makes a copy of it
    //POST: this puts out a copy of the original stack
	Stack(const Stack&); 
    //this puts something at the top of the stack
    //PRE: this takes in the string from main in chars and pushes it into the stack
    //POST: this assigns the top of the stack to the char, and fills the stack
	void push(char c);
    //This takes away the top value
    //PRE: no parameters, but looks at the stack and get rid of the top value
    //POST: this returns the top value of the stack
    char pop();
    //this checks if the stack is empty or not
    //PRE: no parameters, but checks if the stack is empty or not
    //POST: returns the status of whether or not the stack is empty
    bool isEmpty();
    //this checks if the stack
    //PRE: no parameteres, but this checks if the stack is full or not
    //POST: returns the status of the stack, whether or not its full
    bool isFull();
    //this one clears out the stack and makes a new one
    //PRE: no parameters needed
    //POST: this clears out the stack and creates a new one that is empty
    void clearStack();
    //this is to check if it's a palindrome
    //PRE: this takes in the original stack array and assigns it to a string, and assigns its pops to
    //a secon string. then checks if the two are the same
    //POST: outputs true or false on if the two strings are equal to each other 
    bool isPalindrome(Stack& orig);
	
private:
	char* listPtr;
	int maxSize;
	int stackSize;
	int top;
    //this is the copy memeber function
    //PRE: this takes in the original stack and copies all of the data from
    //the first one into the second one
    //POST: this outputs a copy of the first stack
	void copy(const Stack& copy); 
    //this deletes the array
    //PRE: this takes all of the data from the stack and deletes it
    //POST:deletes the stack and sets listPtr to nullptr
    void destroy();
    //this resizes the array
    //PRE: there are no parameters to this. But it takes in the stack and
    //and assigns it to an array with a larger size value
    //POST: sets the old array to the temp one with a bigger size
    void resize();
};

#endif // !STACK_H
