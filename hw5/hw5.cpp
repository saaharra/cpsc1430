//Sarah Nguyen
//March 08, 2021
//hw5.cpp
//This is the driver file that contains the functions to shuffle the card and turn
//over the stacks. This is the main file that plays the game 
#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;
int main()
{
	void shuffle(Stack & obj);
	void turnOver(Stack & deal, Stack & discard);
	Stack dealCards, discard;
	Queue play1, play2;
	bool cont = true;
	bool winner = true;
    //cout statement to explain what the game does
	cout << "Welcome to Silly Little Games' new Card Game \n This is a game where you, the player, compares your card to the top of the discard pile if your card is larger than the one displayed,then you end your turn, if it is equal then you \n";
	cout << "must draw one card from the top of the deal pile and add it to your own hand if it is smaller, then you must draw two cards from the deal pile and add it to your own hand \n";
	cout << "The first player to get rid of all of their cards wins.\n Good Luck!" << endl;
	cout << endl;
	//while loop to continue playing the game until player chooses to not play anymore
	//this goes into the game
	while (cont)
      {
        int player = 1;
		for (int i = 1; i < 14; i++)
		{
            for (int j = 1; j < 5; j++)
			{
				dealCards.push(i);
			}
		}
		//for loop to deal out the cards 
		int cards = 2;
		shuffle(dealCards);
		//round table style, meaning every other is for the other player
		for (int i = 1; i < 14; i++)
		{
			if (cards % 2 == 0)
			{
				play1.enqueue(dealCards.pop());
				cards += 1;
			}
			else
			{
				play2.enqueue(dealCards.pop());
				cards += 1;
			}
		}
		discard.push(dealCards.pop());
		//this is the start of the players section of the game
		while (winner)
		{
			//cout statements to show both players hand 
			cout << "CARDS IN HAND: " << endl;
			cout << "________________" << endl;
			cout << "Player 1: ";
			play1.displayQueue();
			cout << endl;
			cout << "Player 2: ";
			play2.displayQueue();
			cout << endl;
			//this is for player ones turn:
			if (player == 1)
			{
				cout << "Player " << player << "'s turn: \n";
				cout << "Top of the stack is " << discard.peek();
				cout << endl;
				//first check if their card is larger or not 
				if (play1.frontVal() > discard.peek())
				{
					cout << "Your card " << play1.frontVal() << " is larger than " << discard.peek() << endl;
					cout << "Good job!" << endl;
					cout << endl;
					discard.push(play1.dequeue());
					if (play1.isempty())
                    {
                        cout << "The winner is Player 1!" << endl;
						winner = false;
					}
					player = 2;
				}
				else if (play1.frontVal() == discard.peek())
				{
					cout << "Your card is equal to " << discard.peek() << endl;
					cout << "You pick 1 card \n";
					//you must check if there are cards to pull or not
					if (dealCards.isEmpty())
					{
						turnOver(dealCards, discard);
					}
					discard.push(play1.dequeue());
					play1.enqueue(dealCards.pop());
					player = 2;
				}
				else if (play1.frontVal() < discard.peek())
				{
					cout << "Your card " << play1.frontVal() << " is less than " << discard.peek() << endl;
					discard.push(play1.dequeue());
					cout << "You must pick 2 cards \n";
					//check if the deal is empty or if there is only one card left
					if (dealCards.isEmpty() || dealCards.oneCard() != false)
					{
						turnOver(dealCards, discard);
					}
					play1.enqueue(dealCards.pop());
					play1.enqueue(dealCards.pop());
					player = 2;
				}
			}
			//this is for player twos turn:
			else if (player == 2)
			{
				cout << "Player " << player << "'s turn: \n";
				cout << "Top of the stack is " << discard.peek();
				cout << endl;
				//first check if their card is larger or not 
				if (play2.frontVal() > discard.peek())
				{
					cout << "Your card " << play2.frontVal() << " is larger than " << discard.peek() << endl;
					cout << "Good job!" << endl;
					discard.push(play2.dequeue());
					if (play2.isempty())
                    {
                        cout << "The winner is Player 2!" << endl;
                        winner = false;
                      
					}
					player = 1;
				}
				else if (play2.frontVal() == discard.peek())
				{
					cout << "Your card is equal to " << discard.peek();
					discard.push(play2.dequeue());
					cout << "You pick 1 card \n";
					//you must check if there are cards to pull or not
					if (dealCards.isEmpty())
					{
						turnOver(dealCards, discard);
					}
					play2.enqueue(dealCards.pop());
					player = 1;
				}
				else if (play2.frontVal() < discard.peek())
				{
					cout << "Your card " << play2.frontVal() << " is less than " << discard.peek() << endl;
					discard.push(play2.dequeue());
					cout << "You must pick 2 cards \n";
					//check if the deal is empty or if there is only one card left
					if (dealCards.isEmpty() || dealCards.oneCard() != false)
					{
						turnOver(dealCards, discard);
					}
					play2.enqueue(dealCards.pop());
					play2.enqueue(dealCards.pop());
					player = 1;
				}
			}
        }
        winner = false;
        //this is to see if they want to play again or not
        string userinput;
        cout << "Do you want to play this game again? (y/n): ";
        cin >> userinput;
        while(!cin && userinput != "y" && userinput != "n")
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "ERROR IN REQUEST, PLEASE TRY AGAIN: (y/n)" << endl;
            cin >> userinput;
        }
        if (userinput == "y")
        {
            cout << "RESTARTING..." << endl;
            cont = true;
        }
        else
        {
            cout << "Thank you for playing this game!" << endl;
            cont = false;
        }
    }
}

//PRE: this takes in a refernce to a stack (the deal stack) and shuffles the cards based on the random number generated
//POST: this shuffles the deck and has different values in different places 
void shuffle(Stack& obj)
{
	int size = obj.getSize();
	int randNum;
	int* temp = new int[size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = obj.pop();
	}
	srand(time(0));
	//second loop to swap 
	for (int i = 0; i < size; i++)
	{
		randNum = (rand() % size);
		//swap the values around so it "shuffles it"
		int tNum = temp[randNum];
		temp[randNum] = temp[i];
		temp[i] = tNum;
	}
	for (int i = 0; i < size; i++)
	{
		obj.push(temp[i]);
	}
	delete[] temp;

}

//PRE: takes in references to the two stacks and then pushs the pops of the discard into the deal
//POST: this refills the deal stack
void turnOver(Stack& deal, Stack& discard)
{
	int temp = discard.pop();
	while (!discard.isEmpty())
	{
		deal.push(discard.pop());
	}
	deal.push(temp);
}
