//Sarah Nguyen
//Car.cpp
//Program: this is all of the member functions for the driver file to use
#include <iostream>
#include "Car.h"
using namespace std;
Car::Car(int cModel, string cMake)
{
  yearModel = cModel;
  make = cMake;
  speed = 0;
}

int Car::getModel()const
{
  return yearModel;
}

string Car::getMake()const
{
  return make;
}

int Car::getSpeed()const
{
  return speed;
}

void Car::Accelerate()
{
  speed +=5;
}

void Car::Brake()
{
  speed -=5;
}
