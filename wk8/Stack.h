//Sarah Nguyen
//Mrch 02, 2021
//Stack.h
//this is the header file, creates the definitons to call in Stack.cpp
//the class provides Stack.cpp with the member functions it needs in order to
//add data into the stack 
#ifndef STACK_H
#define STACK_H
class Stack
{
public:
    //pre: this is the constructor, there are no pre conditions
    //post: an empty stack
    Stack();
    //pre: this is the destructor, it takes in the stack and deletes its memory
    //post: returns an empty stack that points to nullptr
    ~Stack();
    //pre: takes in the stack and makes a copy of it
    //post: returns a copy of the stack that is in the ()
    Stack(const Stack&);
    //pre: this looks at the = and sets one stack to the other
    //post: sets one stack to the other stack
    Stack& operator=(const Stack& obj);
    //pre: this takes in a double value and pushes it to the top of the stack
    //post: a new value that is on the top of the stack
    void push(double);
    //pre: this looks at the stack and removes the top value
    //post: returns a stack w a new top value since the original one was removed
    double pop();
    //pre: this takes in the stack and checks if its empty or not
    //post: returns a true or false on if the stack is empty
    bool isEmpty();
    //pre: this takes a look a the stack and checks if the stack is full or not
    //post: returns a true or false if its full or not
    bool isFull();
    //pre: this takes a look to see the top value of the stack
    //post: returns the top value of the stack
    double peek();
    //pre: this takes in the stack
    //post: none
    //purpose: this is the sole purpose of testing and seeing what each function does
    //this is a way to display what is in each stack
	void display();
private:
	double * valueArry;
	int maxSize;
	int stackSize;
	int top;
    int getSize();
    //pre: this takes in a stack and makes a copy of it
    //post: returns a copy of a stack
    void copy(const Stack& copy);
    //pre: takes a look at the stack and deletes the memory there
    //post: deletes the stack and sets it to nullptr
    void destroy();
    //pre: this takes in the stack and resizes it
    //post: a stack with a new size
	void resize();
};

#endif // !STACK_H
