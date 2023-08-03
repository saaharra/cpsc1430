//Sarah Nguyen
//arry.cpp
//Program: Create a program that creates a 2D array based on the users
//input, have the user fill in the array. print out the array, print out the
//sums of each rows and the sum of each column
//Input: the number of rows, colums, and numbers to fill in the array
//Process: simple addition
//Output: print out the array, total for the columns, and the total for rows
#include <iostream>
using namespace std;
int main(int argc, char*argv[])
{
  int rows, cols, input;
  int rowSum=0, colSum=0;
  cout << "Input row \n";
  cin >> rows;
  cout << "Input cols \n";
  cin >> cols;

  //for loop to fill the arry
  int **arry = new int*[rows];

  //an embedded for loop to fill up the arry
  for(int i=0; i <rows; i++)
    {
      arry[i] = new int[cols];
      for(int j=0; j < cols; j++)
        {
          cout << "Enter the number for row " << (i+1) << " col " << (j+1) << endl;
          cin >> input;
          arry[i][j] = input;
        }
    }
  //an embedded for loop to print out the arry
  for(int i=0; i < rows; i++)
    {
      for(int j=0; j < cols; j++)
        {
          cout << arry[i][j] << " ";
        }
      cout << endl;
    }
  //sum of the rows
  for(int i=0; i <rows; i++)
    {
      for(int j=0; j<cols; j++)
        {
          rowSum += arry[i][j];
        }
      cout << "Sum of row " << (i+1) << " is " << rowSum << endl;
      rowSum = 0;
    }

  //sum of the cols
  for(int i=0; i<cols; i++)
    {
      for(int j=0; j<rows; j++)
        {
          colSum += arry[j][i];
        }
      cout << "Sum of col " << (i+1) << " is " << colSum << endl;
      colSum = 0;
    }
  delete[] arry;
          

}
