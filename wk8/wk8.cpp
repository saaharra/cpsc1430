//Sarah Nguyen
//wk8.cpp
//March 02, 2021
//This right here is the driver program that tests all of the functions
//within Stack.cpp
#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	Stack firstStack;
	cout << "First Stack" << endl;
	firstStack.push(5.9);
	firstStack.push(8.3);
	firstStack.push(2.3);
    firstStack.push(7.67);
	firstStack.push(1.9);
    firstStack.display();
    cout << "This is to test the Resize, pushing 6" << endl;
    firstStack.push(4.5);
    firstStack.push(11.2);
    firstStack.push(15.3);
    firstStack.push(7.8);
    firstStack.push(10.29);
    firstStack.push(8.2);
    firstStack.display();
	cout << "this is testing two pop" << endl;
	firstStack.pop();
    firstStack.pop();
	firstStack.display();

	//this is for copy constructor
	Stack secondStack(firstStack);
	cout << "Second Stack" << endl;
	cout << "This is after copying the first stack" << endl;
	secondStack.display();
    cout << "This is after pushing another four numbers" << endl;
	secondStack.push(3.4);
    secondStack.push(8.23);
    secondStack.push(9.8);
    secondStack.push(7.1);
	secondStack.display();
	cout << "This does the resize method, push an additional 3" << endl;
	secondStack.push(3.9);
    secondStack.push(8.9);
    secondStack.push(10.3);
    secondStack.display();
    cout << "This is after popping a few numbers" << endl;
    secondStack.pop();
    secondStack.pop();
    secondStack.pop();
    secondStack.display();
	//this one is for assignment operator 
	Stack thirdStack;
	thirdStack = secondStack;
	cout << "Third Stack" << endl;
    thirdStack.display();
    cout << "This is pushing another 4 numbers" << endl;
    thirdStack.push(11.4);
    thirdStack.push(12.3);
    thirdStack.push(4.201);
    thirdStack.push(12.3);
    thirdStack.display();
    cout << "This is after popping twice and pushig once" << endl;
    thirdStack.pop();
    thirdStack.pop();
    thirdStack.push(6.2);
    thirdStack.display();
    

}
