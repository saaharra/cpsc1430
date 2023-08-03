//Sarah Nguyen
//February 19, 2021
//Program: This is the header file for the class message, the purpose for this whole program is to
//ask the user for a file to decode the message and see what the message says
//Source: cplusplus.com for the sorting function
#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
using namespace std;
class hiddenMessage
{
public:
    //Pre: this is the contructor
    //Post: creates an emty list 
    hiddenMessage();
    //pre: this is the destructor, takes in the list and destories it
    //post: returns an empty list
    ~hiddenMessage();
    //pre: this function takes in the list and displays the list
    //post: a printed out list 
    void display();
    //pre: the parameteres here is the letter and the index that are taken in from
    //the file that the person wants to decode.
    //post: a list that contains the letters and the index that the letters go in
    void append(string lettter, int index);
    //pre: this takes in the list and looks at the index values and sorts them in the
    //right order.
    //post: a decoded message 
    void decode();
    //pre: this takes in the list and delete the memory stored in that location
    //post: returns an empty list
	void destroy();

private:
	struct containedMessage
	{
		string letter;
		int index;
		containedMessage* next;
	};
	containedMessage* head;
};
#endif  //MESSAGE_H
