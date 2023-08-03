//Sarah Nguyen
//TicTacToe.cpp
//February 01, 2021
//this is the class file for the tictactoe game
#include <iostream>
#include "TicTacToe.h"
#include <string>
using namespace std;
TicTacToe::TicTacToe()
{
  	for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			 board[i][j] = ' ';
		}
	}
}

void TicTacToe::DisplayBoard()
{
  for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			cout << "[ " << board[i][j] << " ]";
		}
		cout << endl;
	}
}

bool TicTacToe::aWin(char p)
{
  int count;
	//this one checks it starting at the i index first, the first part of the array
	for (int i = 1; i < 4; i++)
	{
		count = 0;
		for (int j = 1; j < 4; j++)
		{
			if (board[i][j] == p)
			{
				count+=1;
			}
		}
		if (count == 3)
		{
			return true;
		}
	}
	//this one checks it starting at the j index, it swaps the order of the one above
	for(int i = 1; i < 4; i++)
	{
		count = 0;
		for (int j = 1; j < 4; j++)
		{
			if (board[j][i] == p)
			{
				count += 1;
			}
		}
		if (count == 3)
		{
			return true;
		}
	}
	count = 0;
	for (int i = 1; i < 4; i++)
	{
		if (board[i][i] == p)
		{
			count+=1;
		}
	}
	if (count==3)
	{
		return true;
	}
	count = 0;
	for (int i = 1, j = 3; i < 4; i++, j--)
	{
		if (board[i][j] == p)
		{
			count += 1;
		}
	}
	if (count == 3)
	{
		return true;
	}
	return false;
}

bool TicTacToe::aTie()
{
  for (int i = 1; i < 4; i++)
	{
		for (int j = 1; j < 4; j++)
		{
			if (board[i][j] == ' ')
				return false;
		}
	}
	return true;
}

void TicTacToe::InsertPiece(int r, int c, char p)
{
  for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
          if (board[i][j] == ' ')
            {
              board[r][c] = p;
            }
        }
    }
}
