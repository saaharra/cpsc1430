//Sarah Nguyen
//listInt.cpp
//Feb. 08, 2021
//Program: this is the class file that holds all of the member functions for ListInt
//this is where we fis this file and add in a copy constructor, assignment operator,
//and a destructor 
#include <iostream>
using namespace std;
#include "listInt.h"

ListInt::ListInt(): head(nullptr)
{
  cout << "In null constructor" << endl;
}

bool ListInt::IsEmpty()const
{
        return (head == nullptr);
}

void ListInt::Add(int x)
{
        NodeInt* nodeptr = new NodeInt(x);
        nodeptr->next = nullptr;
        NodeInt* indexPtr;
        cout << "Adding node..." << endl;
        if(IsEmpty())
                head = nodeptr;
        else
        {
                indexPtr = head;
                while(indexPtr->next)
                        indexPtr = indexPtr->next;
                indexPtr->next = nodeptr;
        }
}

void ListInt::print()const
{
        NodeInt* indexPtr = head;
        cout << "The List:" << endl;
        while(indexPtr)
        {
                cout << indexPtr->data << endl;
                indexPtr= indexPtr->next;
        }
}

ListInt::NodeInt::NodeInt(int dta):data(dta),next(nullptr)
{ }

ListInt::ListInt(ListInt& cList):head(nullptr)
{
  NodeInt* thisPtr = cList.head;
  cout << "In Copy Constructor..." << endl;
  if(IsEmpty())
    {
      NodeInt* newNode = new NodeInt(thisPtr->data);
      newNode->next = nullptr;
      head = newNode;
    }
  while(thisPtr)
    {
      cout << "Copying node..";
      Add(thisPtr->data);
      thisPtr = thisPtr->next;
    }
}

ListInt& ListInt::operator =(ListInt& cList)
{
  cout << "In assignment..." << endl;
  destroy();
  copy(cList);
  return *this;
}

void ListInt::copy(ListInt const & cList)
{
  NodeInt* thisPtr = cList.head;
  while(thisPtr)
    {
      cout << "Copying Node...";
      Add(thisPtr->data);
      thisPtr = thisPtr->next;
    }
  if(!IsEmpty())
    {
      cout << endl;
    }
}
  

void ListInt::destroy()
{
  NodeInt* indexPtr = head;
  NodeInt* temp;
  while(indexPtr)
    {
      cout << "Deleting Node...";
      temp = indexPtr->next;
      delete indexPtr;
      indexPtr = temp;
    }
  head = nullptr;
  cout << endl;
}

ListInt::~ListInt()
{
  destroy();
}
