//Sarah Nguyen
//TicTacToe.h
//February 01, 2021
//This is the header file for the class TicTacToe
#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>
using namespace std;
class TicTacToe
{
public:
  //This is the constructor for the game
  TicTacToe();
  //pre: there are no parameters for this, but it takes in the char arry and
  //prints out the game
  //post: prints out the board game
  void DisplayBoard();
  //pre: takes a look at the game board and checks if there is a winner
  //post: tells who won the game
  bool aWin(char p);
  //pre: takes a look at the board and checks if there is a tie or not
  //post: tells the player if there is a tie or not
  bool aTie();
  //pre: has parameters r, c, and p, r and c being ints for the location of the game piece and p being the players game piece
  //post: a piece is put into the correct spot
  void InsertPiece(int r, int c, char p);
 private:
  char board[3][3];
};
#endif
  
