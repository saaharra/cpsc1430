//Sarah Nguyen
//IntegerSet.cpp
//this is the file that contains all of the member functions to be
//implemented in the drive file
#include <iostream>
#include "IntegerSet.h"
using namespace std; 

//have two sets, one that is empty and you can fill the other 
//takes in  an array if in the size of that array and uses it to initaliz a set object
IntegerSet::IntegerSet() // this one is an empty one
{
  emptySet();
}

//this is the second constructor that takes in the parmeters of an array along with its size
IntegerSet::IntegerSet(int arr[], int size)
{
  emptySet();
  for (int i = 0; i < size; i++)
	{
		if (!validEntry(arr[i]))
		{
			cout << "/n Inlavlid insertion of array index " << arr[i] << endl;
		}
		else
		{
			num[arr[i]] = 1;
		}
	}
}

IntegerSet IntegerSet::unionOfsets(IntegerSet& set)
{ //this creates a third set that is a set-theoretic union of the two existing sets
	IntegerSet temp;
	for (int i = 0; i < 101; i++)
	{
		if (num[i] == 1 || set.num[i] == 1)
		{
			temp.num[i] = 1;
		}
	}
	return temp;
}

//this method takes in another integerset object and finds which values they have in common, then returns those numbers back
IntegerSet IntegerSet::intersectionOfSets(IntegerSet& set)
{
	IntegerSet temp;
	for (int i = 0; i < 101; i++)
	{
		if (num[i] == 1 && set.num[i] == 1)
		{
			temp.num[i] = 1;
		}
	}
	return temp;
}

bool IntegerSet::isEqualTo(IntegerSet &set)
{
	//this checks if the two set arrays are equal to each other
	for (int i = 0; i < 101; i++)
	{
		if (num[i] != set.num[i])
		{
			return false;
		}
		else
		{
			return true;
		}

	}
	return false;
}

//this method takes in a user input and places it into the array 
void IntegerSet::inputSet()
{
	int input;
	bool out = false;
	while (out==false)
	{
		cout << "Enter an element (-1 to end): " << endl;
		cin >> input;
		if (!cin)
		{
			cout << endl;
			cin.clear();
			cin.ignore();
			cin >> input;
		}
		if (input == -1)
		{
			out = true;
		}
		while (input < -1 || input > 101 || num[input] == 1)
		{
			cout << "Invalid entry" << endl;
			cout << "Enter an element (-1 to end): " << endl;
            cin >> input;
            if (input == -1)
              {
                out = true;
              }
		}
		num[input] = 1;
	}
	cout << "Entry Complete" << endl;
}

//this method takes the set within the parameter and empties it
void IntegerSet::emptySet()
{
	for (int i = 0; i < 101; i++)
	{
		num[i] = 0;
	}
}

//this takes in the user input value and see if it fits within the requirements for the "number line"
bool IntegerSet::validEntry(int value)
{
  if (value <= -1 || value >= 101)
    {
      return false;
	}
  else
    {
      return true;
    }  
}

//this is a functio that takes in the array and prints it out
void IntegerSet::printSet()
{
	cout << "{ ";
	for (int i = 0; i < 101; i++)
	{
		if (num[i] == 1)
		{
			cout << i << " ";
		}
	}
	cout << "}" << endl;
}

//this is a method that inserts an element that the user puts in
void IntegerSet::insertElement(int number)
{
	if (validEntry(number) == false)
	{
		cout << "This is an invalid entry" << endl;
	}
	else
	{
		num[number] = 1;
	}
}

//this takes the element that was given and deletes it from the given array
void IntegerSet::deleteElement(int number)
{
	if (validEntry(number) == false)
	{
		cout << "This is an invalid entry" << endl;
	}
	else
	{
		num[number] = 0;
	}
}
