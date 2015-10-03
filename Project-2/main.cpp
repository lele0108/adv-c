// Homework Two
// Jimmy (Sicong) Liu 20076260
// CIS 22B
// September 27th 2015
// XCode 7.0

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// Function prototypes
//int binarySearch (const string [], int, string);
void printThis(const int[][30], int);
void writeTable(const int[][30], const string[], int);
void writeDest(const int[][30], const string[], int);
void writeList(const int[][30], const string[], int);
void writeCheap(const int[][30], const string[], int);

int main () {
  int storage[30][30];
  string airports[30];
  string line;
  ifstream myfile ("airports.txt");
  std::getline (myfile, line);
  int num = atoi(line.c_str());

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
           storage[count-num][i] = number;
           i++;
        }
      }
      count++;
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 

  //printThis(storage, num);
  writeTable(storage, airports, num);
  cout << endl;
  writeDest(storage, airports, num);
  cout << endl;
  writeList(storage, airports, num);
  cout << endl;
  writeCheap(storage, airports, num);

  return 0;
}

void writeTable(const int storage[][30], const string airports[], int num) {
    for (int i = 0; i < num; i++) {
        if (i == 0) {
            cout << "    | ";
            for (int z = 0; z < num; z++)
                cout << airports[z] << " ";
            cout << endl;
            cout << "---   ";
            for (int k = 0; k < num; k++)
                cout << "--- ";
            cout << endl;
        }
        cout << airports[i] << " | ";
        for (int j = 0; j < num; j++) {
            cout << setw(3) << storage[i][j] << " ";
        }
        cout << endl;
    }
}

void writeDest(const int storage[][30], const string airports[], int num) {
    for (int i = 0; i < num; i++) {
        int count = 0;
        string matches[30];
        for (int j = 0; j < num; j++) {
            if (storage[i][j] != 0) {
                matches[count] = airports[j];
                count++;
            }
        }
        cout << airports[i] << " (" << count << "): ";
        for (int j = 0; j < count; j++) {
            cout << matches[j];
            if (j < count - 1)
                cout << ", ";
        }
        cout << endl;
    }
}

void writeList(const int storage[][30], const string airports[], int num) {
    int copy[30][30];
    std::copy(&storage[0][0], &storage[0][0]+30*30,&copy[0][0]);
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (copy[i][j] != 0) {
                copy[j][i] = 0;
                cout << airports[i] << " - " << airports[j] << endl;
            }
        }
    }
}

void writeCheap(const int storage[][30], const string airports[], int num) {
    for (int i = 0; i < num; i++) {
        int price = INT_MAX;
        int count = -1;
        for (int j = 0; j < num; j++) {
            if (storage[i][j] != 0 && storage[i][j] < price) {
                price = storage[i][j];
                count = j;
            }
        }
        if (count > -1) {
            cout << airports[i] << " -> " << airports[count] << " ";
            cout << setw(3) << price << endl;
        }
    }
}

void printThis(const int storage[][30], int num) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << storage[i][j] << " ";
        }
        cout << endl;
    }
}

/**
 MacBook-Pro-2:project-2 jimmyliu$ ./a.out
     | BUR FAT LGB LAX MRY OAK SMF SAN SFO SJC SBO SMO
 ---   --- --- --- --- --- --- --- --- --- --- --- ---
 BUR |   0   0   0   0 122   0   0   0   0   0 316   0
 FAT |   0   0   0   0   0   0   0   0 321 455   0   0
 LGB |   0   0   0 125   0   0   0   0 267   0   0   0
 LAX |   0   0 125   0   0  50   0   0 250   0 370   0
 MRY | 122   0   0   0   0 259   0   0   0   0   0 119
 OAK |   0   0   0  50 259   0   0 129   0   0   0   0
 SMF |   0   0   0   0   0   0   0 111   0   0 125   0
 SAN |   0   0   0   0   0 129 111   0   0   0   0   0
 SFO |   0 321 267 250   0   0   0   0   0 190   0   0
 SJC |   0 455   0   0   0   0   0   0 190   0   0   0
 SBO | 316   0   0 370   0   0 125   0   0   0   0 145
 SMO |   0   0   0   0 119   0   0   0   0   0 145   0
 
 BUR (2): MRY, SBO
 FAT (2): SFO, SJC
 LGB (2): LAX, SFO
 LAX (4): LGB, OAK, SFO, SBO
 MRY (3): BUR, OAK, SMO
 OAK (3): LAX, MRY, SAN
 SMF (2): SAN, SBO
 SAN (2): OAK, SMF
 SFO (4): FAT, LGB, LAX, SJC
 SJC (2): FAT, SFO
 SBO (4): BUR, LAX, SMF, SMO
 SMO (2): MRY, SBO
 
 BUR - MRY
 BUR - SBO
 FAT - SFO
 FAT - SJC
 LGB - LAX
 LGB - SFO
 LAX - OAK
 LAX - SFO
 LAX - SBO
 MRY - OAK
 MRY - SMO
 OAK - SAN
 SMF - SAN
 SMF - SBO
 SFO - SJC
 SBO - SMO
 
 BUR -> MRY 122
 FAT -> SFO 321
 LGB -> LAX 125
 LAX -> OAK  50
 MRY -> SMO 119
 OAK -> LAX  50
 SMF -> SAN 111
 SAN -> SMF 111
 SFO -> SJC 190
 SJC -> SFO 190
 SBO -> SMF 125
 SMO -> MRY 119
 */
