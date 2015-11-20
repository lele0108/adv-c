// Jimmy Liu
// Project 6
// 4 Nov. 2015
// XCode 7.0

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "NumberList.h"
using namespace std;

void readThisFile(NumberList &list);
void deleteCountry(NumberList &list);
void searchCountry(NumberList &list);

int main()
{
   // Define a NumberList object.
   NumberList list;
   //Data a[10] = {{2.5}, {7.9}, {12.6}};
/*
   Country a[3] =
   {
       {"FR", "France",  "Paris", 60656178},
       {"US", "United States", "Washington, DC", 295734134},
       {"CN", "China", "Beijing", 1306313812}
   };
*/
   readThisFile(list);
   // Append some values to the list.
   //list.appendNode(a[1]);
   //list.appendNode(a[2]);
   //list.appendNode(a[0]);

   // Display the values in the list.
   list.displayList();
   deleteCountry(list);
   searchCountry(list);
   return 0;
}

void readThisFile(NumberList &list) {
  string line;
  ifstream myfile ("countries.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      char code[2];
      strcpy(code, line.substr(0, 2).c_str());
      string hold[3];
      string temp;
      int i = 0;
      istringstream ss(line.substr(3));
      while(getline(ss, temp, ';')) {
        temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
        hold[i] = temp;
        i++;
      }
      Data country = {0, {code[0], code[1], '\0'}, hold[0], hold[1], atoi(hold[2].c_str())};
      //Data country = {0.0, code, "France", "Paris", 123};
      list.insertNode(country);
    }
  }
}

void deleteCountry(NumberList &list) {
  string temp;
  cout << "Enter Country Code to Delete: ";
  cin >> temp;
  while (temp != "QUIT") {
    char code[3];
    strcpy(code, temp.c_str());
    list.deleteNode(code);
    cout << "Enter Country Code to Delete: ";
    cin >> temp;
  }
}

void searchCountry(NumberList &list) {
  string temp;
  cout << "Enter Country Code to Search: ";
  cin >> temp;
  while (temp != "QUIT") {
    char code[3];
    strcpy(code, temp.c_str());
    Data hold = list.searchNode(code);
    if (hold.value != -1) {
      for (int i = 0; i < 2; i++) {
        cout << hold.code[i];
      }
      cout << "    ";
      cout << setw(20) << left << hold.name << " ";
      cout << setw(17) << left << hold.capital << " ";
      cout << setw(10) << right << hold.population << endl;
    } else {
      cout << "Not Found!" << endl;
    }
    cout << "Enter Country Code to Search: ";
    cin >> temp;
  }
}