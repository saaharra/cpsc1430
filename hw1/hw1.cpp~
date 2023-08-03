//Sarah Nguyen
//hw1.cpp
//Purpose: create a program that prints out stats based on what the
//user wants to be done, eg. prnting a specific teams win percentages or 
//different ways of sorting the team rankings
//Input: A test file, user input on which option they want to do
//Processing: print out the different team standings
//Sources: none
//Output: print out an array based on what the user wants to be done

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//create the structure of each of the variables that go into the program
struct TeamInfo
{
	string teamName;
	string mascot;
	string ConDiv;
	int wins;
    int losses;
    int ties;
	double wPer;
};

//First function is used to display the whole entire standing
void FullLeague(TeamInfo* arry[], int size);
//second function that is used to look at the individual standings
void individualStanding(TeamInfo*arry[],int size);
//third function to used to sort it by winning percent
void SortStandings(TeamInfo* arry[], int size);
int main()
{
  //this is used to get te user input of what txt file they want to look at
  string FileName, txtContents,contents;
  cout << "Please enter the name of the file that contains the data you want to look at: ";
  cin >> FileName;
  cout << endl;
  cout << endl;
  //do a while loop to find how many lines are in the txt file to create the size of the array
  int size = 0;
  ifstream Files(FileName);
  //check if the file is openable, if not then end the program
  if(!Files.is_open())
    {
      cout << "I'm sorry, but this file does not exist. Thank you for trying to use this program! \n";
      return 0;
    }
  while(getline(Files, txtContents))
    {
      size +=1;
    };
  Files.close();
  //Use the size gotten in the previous part to create an array for Info
  //there was an error when i did string* cause of the different const types in the struct that didnt match
  TeamInfo* tArry = new TeamInfo[size];
  //read in lines of the
  int position = 0;
  string mascot, ConDiv;
  int win, loss,ties;
  double wPer;
  ifstream dfile(FileName);
  while (dfile >> contents)
    {
      dfile >> mascot >> ConDiv >> win >> loss >> ties >> wPer;
      TeamInfo data = { contents, mascot, ConDiv, win, loss, ties, wPer };
	  tArry[position] = data;
	  position++;
    }
  dfile.close();
  int decision = 0;
  while (decision != 4)
    {
      //create the menu for the user to decide on what they want to do
	  cout << "League Standing Analysis Menu\n 1. Display the whole standing\n 2. Display individual division standings\n 3. Display ranking by winning percentage\n 4. Close the program \n";
      cout << endl;
	  cout << "Enter what you want to do: ";
	  cin >> decision;
      cout << endl;
      //switch case to call the option that they want to use
      switch (decision)
        {
        case 1:
          //this is used to display the whole entire standing 
		  FullLeague(&tArry, size);
		  break;
		  //this one is used to display the invidual team standings 
		case 2:
          individualStanding(&tArry, size);
          //indiStanding(&tArray, size);
		  break;
		  //this is used to organize the standing by a winning percentage 
		case 3:
		  SortStandings(&tArry, size);
		  break;
        }
    }
  cout << "Thank you for using this program. Goodbye! \n";
  delete[] tArry;
  return 0;
}

//PRE: This takes in a reference to an array, and the size of the array
//and prints out the standing of the little league
//POST: this prints out and displays the data of what is taken from the
//little league or any league text file 
void FullLeague(TeamInfo* arry[], int size)
{
  cout << setw(16);
  cout << "Team";
  cout << setw(16);
  cout << "Mascot";
  cout << setw(16);
  cout << "Con/Division";
  cout << setw(16);
  cout << "Wins";
  cout << setw(16);
  cout << "Losses";
  cout << setw(16);
  cout << "Ties";
  cout << setw(16);
  cout << "Winning%";
  cout << setw(16);
  cout << endl;
  for (int i = 0; i < size; i++)
    {
      cout << setw(16);
      cout << ((*arry)[i]).teamName << " ";
      cout << setw(16);
      cout << ((*arry)[i]).mascot << " ";
      cout << setw(16);
      cout << ((*arry)[i]).ConDiv << " ";
      cout << setw(16);
      cout << ((*arry)[i]).wins << " ";
      cout << setw(16);
      cout << ((*arry)[i]).losses << " ";
      cout << setw(16);
      cout << ((*arry)[i]).ties << " ";
      cout << setw(16);
      cout << ((*arry)[i]).wPer << endl;
    }
}

//PRE: This takes in a referce to the team information array and the size of the array
//and looks for the specific standing that the user wants
//POST: this displays the individual standing that the user wants to look at
void individualStanding(TeamInfo*arry[],int size)
{
  string con;
  string div;
  string fullName;
  cout << "Displaying the Division: \n";
  cout << "What conference do you want to look at?: ";
  cin >> con;
  int s = con.size();
  for(int i = 0; i < s; i++)
    {
      if(islower(con[i]))
        {
          con[i] = toupper(con[i]);
        }
    }
  cout << "What division in " << con << " would you like (East, West, South, North)?\n";
  cin >> div;
  //this checks to see if the first letter is lowercase, if it is, then change it to uppercase 
  if(islower(div[0]))
    {
      div[0] = toupper(div[0]);
    }
  //make the complete name between the conference and division
  fullName = con + "_" + div;
  cout << "The total division for " << fullName << " " << endl;
  //go through the list and check if the name is there
  for(int i = 0; i < size; i++)
    {
      //use an if statement that goes through the whole entire text file to look for the name
      //displays them if they're the same
      if((*arry)[i].ConDiv.find(fullName) != string::npos)
        {
          cout << setw(16);
          cout << (*arry)[i].teamName << " ";
          cout << setw(16);
          cout << (*arry)[i].mascot << " ";
          cout << setw(16);
          cout << (*arry)[i].ConDiv << " ";
          cout << setw(16);
          cout << (*arry)[i].wins << " ";
          cout << setw(16);
          cout << (*arry)[i].losses << " ";
          cout << setw(16);
          cout << ((*arry)[i]).ties << " ";
          cout << setw(16);
          cout << (*arry)[i].wPer << endl;
        }
    }
  cout << endl;
}

//PRE: This takes in a pointer to the TeamInform array and the size of the array and goes through and sorts
//the array based on the winning percentage of the array
//POST: It puts out an array that is sorted and organized by the winning percentage of the league txt file
void SortStandings(TeamInfo* arry[], int size)
{
    cout << "Sorting the standings by the winning percentage...\n" ;
    //create a for loop to go through each line and look at the winning percentage to sort
    TeamInfo* temp = new TeamInfo[size];
    for (int j = 0; j < size; j++)
      {
        int min = j;
        //Initialize the variable for the largest number
        for (int i = j + 1; i < size; i++)
        {
          if ((*arry)[min].wPer < (*arry)[i].wPer)
              {
                min = i;
              }
        }
        if (min != j)
          {
            temp[j] = (*arry)[min];
            (*arry)[min] = (*arry)[j];
            (*arry)[j] = temp[j];
          }
      }
    delete[] temp;
}
