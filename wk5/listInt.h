#ifndef LISTINT_H
#define LISTINT_H
#include <iostream>
using namespace std;

class ListInt
{
private:
  class NodeInt
  {
  public:
    NodeInt(int dta = 0);
    int data;
    NodeInt* next;
  };
  NodeInt* head;
  //pre: takes a look at the list and deletes the memory held at that point in the list
  //post: an empty list where the head points to null
  void destroy();
  //pre: takes a refernece to a list and creates a copy of it
  //post: creates a copy of the list that was taken in by the function
  void copy(ListInt const &cList);
public:
  //this is the constructor
  ListInt();
  //this is the copy constructor
  ListInt(ListInt& cList);
  //this is the assignment operator 
  ListInt& operator=(ListInt& cList);
  //pre: this takes in the list and checks if the head is empty or not
  //post: returns whether or not the list is empty
  bool IsEmpty()const;
  //pre: takes in a number and adds it to the list
  //post: a new number added to the list
  void Add(int x);
  //pre: takes the list and prints it out
  //post: prints out the list 
  void print()const;
  //this is the destructor 
  ~ListInt();
};

#endif
