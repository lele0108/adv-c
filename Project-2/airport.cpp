// Homework One
// Jimmy (Sicong) Liu 20076260
// CIS 22B
// September 27th 2015
// XCode 7.0

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Function prototypes
//int binarySearch (const string [], int, string);


int main () {
  string line;
  ifstream myfile ("airports.txt");
  std::getline (myfile, line);
  int num = atoi(line.c_str());
  string *airports = new string[num];
  int storage[num][num];

  if (myfile.is_open()) { 
    int count = 0;
    while ( getline (myfile,line) ) {
      if (count < num) { //airport codes
        airports[count] = line;
      }
      else { //numbers
        std::stringstream stream(line);
        int i = 0;
        while(1) {
           int number;
           stream >> number;
           if(!stream)
              break;
           storage[count][i] = number;
           i++;
        }
      }
      count++;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
