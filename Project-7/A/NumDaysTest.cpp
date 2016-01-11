// Jimmy Liu
// Project 7
// December 4 2015 (Extension requested)
// XCode 7.0

#include <iostream>
#include "NumDays.h"
using namespace std;

// Main function of the program
int main() {
	NumDays hello(8);
	cout << "Number of Days: " << hello.getDay() << endl;
	hello++;
	cout << "Number of Days: " << hello.getDay() << endl;
	hello--;
	cout << "Number of Days: " << hello.getDay() << endl;
	hello = hello + hello;
	cout << "Number of Days: " << hello.getDay() << endl;
	hello = hello - hello;
	cout << "Number of Days: " << hello.getDay() << endl;
	return 0;
}

/* 
MacBook-Pro-3:A jimmyliu$ ./a.out
Number of Days: 1
Number of Days: 1.125
Number of Days: 1
Number of Days: 2
Number of Days: 0
*/