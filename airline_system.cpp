#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>

using namespace std;

class AirLine
{
private:
 string Flight, Des, Dep;
 int Seats;

public:
 AirLine(string Flight, string Des, string Dep, int Seats)
 {
  this->Flight = Flight;
  this->Des = Des;
  this->Dep = Dep;
  this->Seats = Seats;
 }

 string getFlight() { return Flight; }
 string getDes() { return Des; }
 string getDep() { return Dep; }
 int getSeats() { return Seats; }
 void updateSeats(int bookedSeats) { Seats -= bookedSeats; }
};

// Function to display flight details
void display()
{
 ifstream in("Flight.txt");
 if (!in)
 {
  cout << "Error: File not found!" << endl;
  return;
 }
 string line;
 while (getline(in, line))
 {
  cout << line << endl;
 }
 in.close();
}

// Function to update flight seat availability in file
void updateFlightSeats(string FlightNo, int bookedSeats)
{
 ifstream in("Flight.txt");
 if (!in)
 {
  cout << "Error: File not found!" << endl;
  return;
 }

 vector<string> flightData;
 string line;
 bool updated = false;

 while (getline(in, line))
 {
  stringstream ss(line);
  string flight, des, dep;
  int seats;
  ss >> flight >> des >> dep >> seats;

  if (flight == FlightNo)
  {
   if (seats >= bookedSeats)
   {
    seats -= bookedSeats;
    cout << "Ticket Booked Successfully! Updated seats: " << seats << endl;
    updated = true;
   }
   else
   {
    cout << "Not enough seats available!" << endl;
    in.close();
    return;
   }
  }
  stringstream updatedLine;
  updatedLine << flight << " " << des << " " << dep << " " << seats;
  flightData.push_back(updatedLine.str());
 }
 in.close();

 if (!updated)
 {
  cout << "Flight not found!" << endl;
  return;
 }

 ofstream out("Flight.txt");
 for (const string &flightLine : flightData)
 {
  out << flightLine << endl;
 }
 out.close();
}

// Main function
int main()
{
 // Writing initial flight data
 ofstream out("Flight.txt");
 if (!out)
 {
  cout << "Error: File not created!" << endl;
  return 1;
 }
 out << "F101 Bhubaneswar Delhi 50" << endl;
 out << "F102 Hyderabad Mumbai 40" << endl;
 out << "F103 Bangalore Noida 2" << endl;
 out.close();

 bool exit = false;
 while (!exit)
 {
  cout << "\nWelcome to Airline Management System" << endl;
  cout << "------------------------------------" << endl;
  cout << "1. Display Flight Details" << endl;
  cout << "2. Book a Ticket" << endl;
  cout << "3. Exit" << endl;
  cout << "Enter your choice: ";

  int choice;
  cin >> choice;

  if (cin.fail())
  {
   cin.clear();
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
   cout << "Invalid input! Please enter a number." << endl;
   continue;
  }

  switch (choice)
  {
  case 1:
   display();
   cout << "Press Enter to continue...";
   cin.ignore();
   cin.get();
   break;

  case 2:
  {
   cout << "Enter Flight No.: ";
   string FlightNo;
   cin >> FlightNo;
   cout << "Enter No. of Seats: ";
   int RequestedSeats;
   cin >> RequestedSeats;

   if (cin.fail() || RequestedSeats <= 0)
   {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid seat number!" << endl;
    continue;
   }

   updateFlightSeats(FlightNo, RequestedSeats);
   cout << "Press Enter to continue...";
   cin.ignore();
   cin.get();
   break;
  }

  case 3:
   cout << "Exiting system. Thank you!" << endl;
   exit = true;
   break;

  default:
   cout << "Invalid choice! Please try again.\n";
   break;
  }
 }
 return 0;
}
