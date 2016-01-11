// Jimmy Liu
// Project 6
// 16 Nov. 2015
// XCode 7.0

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "CountryList.h"
using namespace std;

bool readThisFile(CountryList &list);
void deleteCountry(CountryList &list);
void searchCountry(CountryList &list);

int main()
{
   // Define a CountryList object.
   CountryList list;
   if (!readThisFile(list)) {
    cout << "There was a problem reading the file" << endl;
    return 0;
   }
   list.displayList();
   deleteCountry(list);
   searchCountry(list);
   return 0;
}

// Reads the file using two stringstreams and uses semicolon delimination
bool readThisFile(CountryList &list) {
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
        if (temp.substr(0,1) == " ") {
          temp.substr(1, temp.length());
        }
        hold[i] = temp;
        i++;
      }
      Data country = {0, {code[0], code[1], '\0'}, hold[0], hold[1], atoi(hold[2].c_str())};
      list.insertNode(country);
    }
    return true;
  }
  return false;
}

// Prompts the user to delete countries from a list
void deleteCountry(CountryList &list) {
  string temp;
  cout << "Enter Country Code to Delete: ";
  cin >> temp;
  while (temp != "QUIT") {
    char code[3];
    strcpy(code, temp.c_str());
    if (list.deleteNode(code)) {
      cout << "Country has been deleted" << endl;
    } else {
      cout << "Country not found!" << endl;
    }
    cout << "Enter Country Code to Delete: ";
    cin >> temp;
  }
}

// Allows the user to search for countries in the list
void searchCountry(CountryList &list) {
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

/*
MacBook-Pro-3:project-6 jimmyliu$ ./Country
Code  Name                  Capital          Population
AU    Australia             Canberra           20090437
BR    Brazil                Brasilia          186112794
BU    Bulgaria              Sofia               7262675
CA    Canada                Ottawa             32805041
CN    China                 Beijing          1306313812
DO    Dominican Republic    Santo Domingo       8950034
EG    Egypt                 Cairo              77505756
ES    Spain                 Madrid             40341462
FJ    Figi                  Suva                 893354
FR    France                Paris              60656178
GR    Greece                Athens             10668354
HU    Hungary               Budapest           10006835
IR    Iran                  Tehran             68017860
JA    Japan                 Tokyo             127288419
LI    Liechtenstein         Vaduz                 33717
MC    Monaco                Monaco                32409
MU    Mauritius             Port Louis          1230602
MX    Mexico                Mexico City       106202903
NP    Nepal                 Kathmandu          27676547
RU    Russia                Moscow            143420309
TW    Taiwan                Taipei             22894384
US    United States         Washington, DC    295734134
Enter Country Code to Delete: AU
Country has been deleted
Enter Country Code to Delete: BR
Country has been deleted
Enter Country Code to Delete: XY
Country not found!
Enter Country Code to Delete: QUIT
Enter Country Code to Search: US
US    United States         Washington, DC    295734134
Enter Country Code to Search: AU
Not Found!
Enter Country Code to Search: QUIT
*/