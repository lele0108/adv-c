// Jimmy Liu
// Project 7
// December 4 2015 (Extension requested)
// XCode 7.0

#include <iostream>
#include "NumDays.h"
using namespace std;

// Constructor with no params
NumDays::NumDays() {
	daysCount = 0;
}

// Constructor with number of hours as param
NumDays::NumDays(int hours) {
	daysCount = 0;
	calculate(hours);
}

// Constructor with number of days as param
NumDays::NumDays(double days) {
	daysCount = days;
}

// Calculates from hours to days
void NumDays::calculate(int hours) {
	daysCount = (double)hours / 8;
}

// Sets the day from number of hours
void NumDays::setHour(int hours) {
	calculate(hours);
}

// Returns the number of days
double NumDays::getDay() const {
	return daysCount;
}

// Overloaded operator allows addition of two NumDays
NumDays NumDays::operator+(const NumDays &second) {
	double count = this->getDay() + second.getDay();
	NumDays temp(count);
	return temp;
}

// Overloaded operator allows subtraction of two NumDays
NumDays NumDays::operator-(const NumDays &second) { 
	double count = this->getDay() - second.getDay();
	NumDays temp(count);
	return temp;
}

// Overloaded operator allows increment of NumDays
NumDays NumDays::operator++(int) {
	double count = this->getDay();
	int hours = count * 8;
	hours++;
	this->setHour(hours);
	return *this;
}

// Overloaded operator allows decrement of NumDays
NumDays NumDays::operator--(int) {
	double count = this->getDay();
	int hours = count * 8;
	hours--;
	this->setHour(hours);
	return *this;
}
