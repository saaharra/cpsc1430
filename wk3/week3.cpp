//Sarah Nguyen
//week3.cpp
//Purpose: this is the driver program used to test out the class files
#include <iostream>
#include "Car.h"
using namespace std;
int main()
{
  Car myCar(2020, "Honda Civic");
  cout << "My car is a " << myCar.getModel()<< " " << myCar.getMake() << endl;
  cout << "The speed of my " << myCar.getMake() <<" is currently at " << myCar.getSpeed() << endl;
  cout << endl;
  cout << "ACCELERATING! \n";
  for(int i =0; i < 5; i++)
    {
      myCar.Accelerate();
      cout << myCar.getSpeed() << endl;
    }
  cout << endl;
  cout << "BRAKING! \n";
  for(int i = 0; i < 5; i++)
    {
      myCar.Brake();
      cout << myCar.getSpeed() << endl;
    }
}
