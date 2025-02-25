#include <iostream>
#include <fstream> //for file handling
#include <windows.h>
#include <sstream> // for conversion to string

using namespace std;

class AirLine{
 private:
 string Flight, Des, Dep;
 int Seats;

 public:
 AirLine(string Flight, string Des, string Dep, int Seats){
  this -> Flight = Flight;
  this -> Des = Des;
  this -> Dep = Dep;
  this -> Seats = Seats;
 }
}
