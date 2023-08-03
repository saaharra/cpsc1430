//Sarah Nguyen
//IntegerSet.h
//This is the header fie for IntegerSet.cpp
#ifndef INTEGERSET_H
#define INTEGERSET_H
class IntegerSet
{
public:
	//Pre: this takes in an arry and the size
	//Post: returns a filled array
	IntegerSet(int arry[], int size);
	//Pre: takes in a reference to the class IntegerSet
	//Post: returns a third set that is a union of the two existing sets
	IntegerSet unionOfsets(IntegerSet &set);
	//Pre: This takes in a reference to a set thats apart of the IntegerSet class
	//Post: returns the numbers that these two sets have in common
    IntegerSet intersectionOfSets(IntegerSet &set);
    //Pre: takes in a number that the user inputed and places it into the set
    //post: a new number is added into the set
    void insertElement(int number);
    //pre: takes in the number that was put into the set and deletes it
    //post: takes out the number from the set 
	void deleteElement(int number);
	//Pre: this takes the set and prints out the set
	//Post: prints out the set of numbers 
	void printSet();
	//Pre: takes in an integerset and compares the two exsiting sets together
	//Post: returns whether or not the two sets are the same 
	bool isEqualTo(IntegerSet& set);
	//Pre: takes a set and empties it
	//Post: returns an empty set 
	void emptySet();
	//Pre: this calls in the user input and places it into an arry
	//Post: returns a filled up arry 
	void inputSet();
	//Pre: takes in a value that the user did and checks if it is a value input or not
	//Post: returns if the value works or not, if it does then it goes into the arry
	bool validEntry(int value);
	IntegerSet(); //this is one array that doesnt hace any parameters
private:
	int num[101];
};

#endif // !INTEGERSET_H
