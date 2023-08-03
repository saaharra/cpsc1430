//Sarah Nguyen
//March 06, 2021
//hw4.cpp
//this is the driver program that gets the user file input and reads the file in
//this ends up calling the functions from the class
#include <iostream>
#include <string>
#include <fstream>
#include "Stack.h"
using namespace std;


int main()
{
	Stack firstStack;
	string input, content;
	int times = 0;
	//char character;
	bool cont = true;
	bool palindrome = true;
	while (cont)
      {
        cout << "Enter in the file you want to look at: ";
		cin >> input;
			ifstream textfile(input);
			//check if the file is openable or not
			while (!textfile.is_open())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Error opening up this file, please enter another one: ";
				cin >> input;
				textfile.open(input);
			}
			while (getline(textfile, content))
			{
				int size = content.length();
				cout << content << endl;
				for (int i = 0; i < size; i++)
				{
					if (content[i] >= 'A' && content[i] <= 'Z')
					{
						content[i] = content[i] + 32; // change the capital letters to lowercase letters
					}
					else if (content[i] < 'a' || content[i] > 'z') {
						content.erase(i, 1);
						size--;
						i--;
					}
					else if (content[i] == ' ') //this deletes the spaces
					{
						content.erase(i, 1);
						size--;
						i--;
					}
				}
				for (int i = 0; i < size; i++)
				{
					firstStack.push(content[i]);
				}
				Stack secondStack(firstStack);
				palindrome = firstStack.isPalindrome(secondStack);
				if (palindrome)
				{
					times += 1;
				    cout << "This is a palindrome" << endl;
                    cout << endl;
                }
                else
				{
					cout << "This is not a palindrome" << endl;
                    cout << endl;
				}
			}
			cout << "There are " << times << " palindromes in this file." << endl;
			times = 0;
			cout << endl;
			cout << "Would you like to find palindromes in another file? y for yes, n for no: ";
			cin >> input;
			while (!cin.fail() && input != "y" && input != "n");
			if (input == "y")
            {
              cont = true;
            }
			else
			{
				cout << "Thanks for using this program!" << endl;
				cont = false;
			}
	}
}


