// Driver program to do basic testing on a listInt class.
#include <iostream>
using namespace std;
#include "listInt.h" 
 
int main() {
	ListInt myList;
	myList.Add(1);
	myList.Add(2);
	myList.Add(3);
    cout << "First List. " << endl;
	myList.print();

    ListInt secondList (myList);
    secondList.Add(4);
    secondList.Add(5);
    cout << "Second List. " << endl;
    secondList.print();

    ListInt emptyList;
    cout << "Empty List. " << endl;
    emptyList.print();

    secondList = emptyList;
    cout << "Second List Again. " << endl;
    secondList.print();
    
    myList.Add(6);
    secondList = myList;
    cout << "First List Again. " << endl;
    myList.print();
    cout << "Second List Again. " << endl;
    secondList.print();
	return 0;
}
