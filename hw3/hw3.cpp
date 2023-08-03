//Sarah Nguyen
//February 19, 2021
//This is the driver file, this contains the main and what to pass through.
//This takes in the user input to see what file to look at and what they want to
//do with said file, whether they want to display the message or to decode it
#include <iostream>
#include <string>
#include <fstream>
#include "message.h"
using namespace std;
int main(int argc, char *argv[])
{
	hiddenMessage displayMessage;
	//check which file they wanna do
	string inputFile, content;
	cout << "Enter the file name: ";
	cin >> inputFile;
	ifstream letterFile(inputFile);
    //this checks if the file exists or not 
	while (!letterFile.is_open())
	{
		cin.clear();
		cin.ignore(256, '\n');
		cout << "There is an error opening this file. Please enter another one: ";
		cin >> inputFile;
		letterFile.open(inputFile);
	}
    //this reads in the file and puts it in the correct categories
	while (getline(letterFile,content))
	{
		displayMessage.append(content.substr(0, 1), stoi(content.substr(1, content.size())));
	}
	letterFile.close();

	int decision = 0;
	while (decision!=4)
	{
        cout << endl;
        cout << "Menu" << endl;
		cout << " 1. Decode the message \n 2. Print the message \n 3. Enter another secret message \n 4. Exit the Program" << endl;
		cin >> decision;
		switch (decision)
		{
		case 1: //case one is to decode the message
            displayMessage.decode();
			break;
		case 2: // case two is to print the message
            cout << "The message is: " << endl;
			displayMessage.display();
			break;
		case 3: // case three is to ask for a new file to decode
            displayMessage.destroy();
			string inputFile, content;
			cout << "Enter the file name: ";
			cin >> inputFile;
			ifstream letterFile(inputFile);
			while (!letterFile.is_open())
            {
                cin.clear();
		        cin.ignore(256, '\n');
		        cout << "There is an error opening this file. Please enter another one: ";
		        cin >> inputFile;
		        letterFile.open(inputFile);
	        }
			while (getline(letterFile, content))
			{
				displayMessage.append(content.substr(0, 1), stoi(content.substr(1, content.size())));
			}
			letterFile.close();
			break;
		}
	}
    cout << "Thank you for using this program! Goodbye :)" << endl;
}
