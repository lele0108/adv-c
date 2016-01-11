// Jimmy Liu
// Project 7
// December 4 2015 (Extension Requested)
// XCode 7.0

// This program demonstrates the Car, Truck, and SUV
// classes that are derived from the Automobile class.
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include "Car.h"
#include "Truck.h"
#include "SUV.h"
using namespace std;

void readThisFile();
void printCar(Car &car);
void printTruck(Truck &truck);
void printSUV(SUV &suv);

// Main test function of program
int main()
{
    readThisFile();
    return 0;
}

// Reads text file and creates a single Car, Truck, and SUV
void readThisFile() {
  string line;
  ifstream myfile ("cars.txt");
  if (myfile.is_open()) {
    int j = 0;
    while (getline(myfile, line)) {
      string hold[5];
      string temp;
      int i = 0;
      istringstream ss(line.substr(3));
      while(getline(ss, temp, ',')) {
        hold[i] = temp;
        i++;
      }
      if (j == 0) {
        Car car(hold[0], atoi(hold[1].c_str()), atoi(hold[2].c_str()), atoi(hold[3].c_str()), atoi(hold[4].c_str()));
        printCar(car);
      } else if (j == 1) {
        Truck truck(hold[0], atoi(hold[1].c_str()), atoi(hold[2].c_str()), atoi(hold[3].c_str()), hold[4]);
        printTruck(truck);
      } else {
        SUV suv(hold[0], atoi(hold[1].c_str()), atoi(hold[2].c_str()), atoi(hold[3].c_str()), atoi(hold[4].c_str()));
        printSUV(suv);
      }
      j++;
    }
  }
}

// Prints the car
void printCar(Car &car) {
    cout << fixed << showpoint << setprecision(2);
    cout << "We have the following car in inventory:\n"
         << car.getModel() << " " << car.getMake()
         << " with " << car.getDoors() << " doors and "
         << car.getMileage() << " miles.\nPrice: $"
         << car.getPrice() << endl << endl;
}

// Prints the truck
void printTruck(Truck &truck) {
    cout << fixed << showpoint << setprecision(2);
    cout << "We have the following truck in inventory:\n"
         << truck.getModel() << " " << truck.getMake()
         << " with " << truck.getDriveType()
         << " drive type and " << truck.getMileage() 
         << " miles.\nPrice: $" << truck.getPrice() 
         << endl << endl;
}

// Prints the SUV
void printSUV(SUV &suv) {
    cout << fixed << showpoint << setprecision(2);
    cout << "We have the following SUV in inventory:\n"
         << suv.getModel() << " " << suv.getMake()
         << " with " << suv.getMileage() << " miles and "
         << suv.getPassengers() << " passenger capacity.\n"
         << "Price: $" << suv.getPrice() << endl;
}

/*
MacBook-Pro-3:C jimmyliu$ ./a.out
We have the following car in inventory:
2007  with 4 doors and 50000 miles.
Price: $15000.00

We have the following truck in inventory:
2006 ota with  4WD drive type and 40000 miles.
Price: $12000.00

We have the following SUV in inventory:
2005 vo with 30000 miles and 5 passenger capacity.
Price: $18000.00
*/