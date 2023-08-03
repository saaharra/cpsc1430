//Sarah Nguyen
//Car.h
//Purpose: this is the header file for the class called Car
#ifndef CAR_H
#define CAR_H
#include <iostream>
using namespace std;
class Car
{
 private:
  int yearModel;
  string make;
  int speed;
 public:
  //constructor to get the model and make make of the car
  Car(int cModel = 0, string cMake = "");
  //these are the getter functions, it get the make, model, and speed of the car
  int getModel()const;
  string getMake()const;
  int getSpeed()const;
  //PRE: this takes in the car and add five to the speed to accelerate the car
  //POST: adds five to the car
  void Accelerate();
  //PRE: this takes in the car and substracs five from the speed to accelerate the car
  //POST: substracts five from the car
  void Brake();
};
#endif
