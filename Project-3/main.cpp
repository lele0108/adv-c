// Homework Three
// Jimmy (Sicong) Liu 20076260
// CIS 22B
// October 17th 2015
// XCode 7.0

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

double** readThisFile(double**);
void printStuff(double**);
void insertionSort(double[], int);
double** tableSort(double**);
int computeSize(double**);

int main() {
	double **pointers;
	pointers = readThisFile(pointers);
  int count = 0;
  while (pointers[count] != NULL) {
    insertionSort(pointers[count], pointers[count][0]);
    count++;
  }
  pointers = tableSort(pointers);
  printStuff(pointers);
	return 0;
}

// Reads the file and stores it into storage and airports array
double** readThisFile(double **pointers) {
  string line;
  ifstream myfile ("ragged.txt");
  getline (myfile, line);
  int num = atoi(line.c_str());
  pointers = new double *[num + 1];
  if (myfile.is_open()) { 
    int count = 0;
    while ( getline (myfile,line) ) {
      int innercounter = 1;
      double number = -1.0;
    	stringstream stream(line);
      stream >> number;
      pointers[count] = new double[(int)number + 1];
      pointers[count][0] = number;
    	while (stream >> number) {
        pointers[count][innercounter] = number;
        innercounter++;
      }
      count++;
    }
    myfile.close();
    pointers[num] = NULL;
    return pointers;
  }
  else cout << "Unable to open file";
  return 0;
}

void printStuff(double **pointers) {
  int size = 0;
  size = computeSize(pointers);
  cout << "The ragged array has " << size << " rows:" << endl;
  int count = 0;
  while (pointers[count] != NULL) {
    int temp = pointers[count][0];
    for (int j = 0; j < temp + 1; j++) {
      if (j == 0) {
        cout << setw(2) << fixed << setprecision(0) << pointers[count][j] << " ";
      } else {   
        cout << setw(5) << fixed << setprecision(1) << pointers[count][j] << " ";
      }
    }
    cout << endl;
    count++;
  }
}

//**************************************************************
// Definition of function insertionSort.                       *
// This function performs an ascending order insertion sort on *
// array. size is the number of elements in the array.         *
//**************************************************************

void insertionSort(double array[], int size)
{
   for (int curr = 2; curr < size + 1; curr++) {
      double hold = array[curr];                   // copy current element to hold
      int back = curr - 1;
      while (back >= 1 && hold > array[back])   // search where to insert the current element
      {
          array[back + 1] = array[back];        // shift to the right
          back--;
      }
      array[back + 1] = hold;                   // put hold back to the array
   }
}

double** tableSort(double **pointers) {
  int curr = 1;
  while(pointers[curr] != NULL) {
      double *hold = pointers[curr];                   // copy current element to hold
      int back = curr - 1;
      while (back >= 0 && hold[0] > pointers[back][0])   // search where to insert the current element
      {
          pointers[back + 1] = pointers[back];        // shift to the right
          back--;
      }
      pointers[back + 1] = hold;                   // put hold back to the array
      curr++;
  }

  return pointers;
}

int computeSize(double **pointers) {
  int count = 0;
  while(pointers[count] != NULL) 
    count++;
  return count;
}
