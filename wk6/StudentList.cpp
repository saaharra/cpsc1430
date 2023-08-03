
//Sarah Nguyen
//Purpose: create a student list that has the students first and last name along with your grade
//this is practice appending, inserting,searching for a specific inside of a node
//and deleting a node from a linked list
//Input: the input is just using the insert or append function to put into the linked list you created
//Processing: this gets added to the linked list
//Output: prints out the list if displayed is call

#include <iostream>
#include "StudentList.h"
using namespace std;
//this is the class file
StudentList::StudentList() : head(nullptr)
{
}


void StudentList::displayList()const
{
	personObj* nodePtr = head;
	while(nodePtr)
	{
		cout << nodePtr->fname << " " << nodePtr->lname << " " << nodePtr->grade << endl;
		nodePtr = nodePtr->next;
	}
}

void StudentList::append(string fn, string ln, double g)
{
	personObj* nodePtr;
	personObj* nextNode;
	nextNode = new personObj;
	nextNode->next = nullptr;

	nextNode->fname = fn;
	nextNode->lname = ln;
	nextNode->grade = g;
	if (!head)
	{
		head = nextNode;
	}
	else
	{
		nodePtr = head;
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->next = nextNode;
	}

}


void StudentList::deleteNode(string fn, string ln)
{
	personObj* indexPtr;
	personObj* nextNode;
	if (!head) // this checks if the node is empty or not
	{
		return;
	}

	if (head->fname == fn && head->lname == ln)
	{
		indexPtr = head->next;
		delete head;
		head = indexPtr;
	}
	
	else
	{
		indexPtr = head;
		while (indexPtr && indexPtr->fname != fn && indexPtr->lname != ln)
		{
			nextNode = indexPtr;
			indexPtr = indexPtr->next;
		}
		if (indexPtr && indexPtr->fname == fn && indexPtr->lname == ln)
		{
			nextNode->next = indexPtr->next;
			delete indexPtr;
		}
	}
}

bool StudentList::search(string fn, string ln)
{
	personObj* nodePtr;
	nodePtr = head;
	while (nodePtr)
	{
		if (nodePtr->fname == fn && nodePtr->lname == ln)
		{
			return true;
		}
		nodePtr = nodePtr->next;
	}
	return false;
}

void StudentList::insert(string fn, string ln, double g)
{
	personObj* nodePtr;
	personObj* nextNode;
	personObj* newNode;
	newNode = new personObj;
	newNode->fname = fn;
	newNode->lname = ln;
	newNode->grade = g;
	if (head == nullptr)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;
		nextNode = nullptr;
		while (nodePtr && newNode->grade < g)
		{
			nextNode = newNode;
			nodePtr = nodePtr->next;
		}
		if (nextNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			nextNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
	
}

StudentList::~StudentList()
{
	personObj* nodePtr = head;
	personObj* nextNode;
	while (nodePtr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	head = nullptr;
}

