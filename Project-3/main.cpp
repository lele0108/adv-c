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
void deleteMem(double**);

int main() {
	double **pointers;
	pointers = readThisFile(pointers);
  if (pointers == NULL) //If file failed to be read program exits
    return 0;
  int count = 0;
  while (pointers[count] != NULL) {
    insertionSort(pointers[count], pointers[count][0]);
    count++;
  }
  pointers = tableSort(pointers);
  printStuff(pointers);
  deleteMem(pointers);
  //printStuff(pointers);
	return 0;
}

// Reads the file and creates dynamic double arrays to store data
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
  return NULL;
}

// Prints the table of the arrays
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
        cout << setw(6) << fixed << setprecision(1) << pointers[count][j] << " ";
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

// Modified insertionSort for descending order for doubles, ignores first element
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

// Sorts the array of pointers to double arrays, NULL deliminited
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

// Computes the size of the array 
int computeSize(double **pointers) {
  int count = 0;
  while(pointers[count] != NULL) 
    count++;
  return count;
}

// Function to delete memory of the 2-D ragged array
void deleteMem(double **pointers) {
  int count = 0;
  while (pointers[count] != NULL) {
    delete[] pointers[count];
    count++;
  }
  delete[] pointers;
}

/*
The ragged array has 13 rows:
11    9.0    8.9    7.5    6.2    5.3    3.5    2.1    1.6    1.2    1.2    0.8 
 7  888.8   99.9   56.8   54.6   23.5   12.2   10.8 
 6  888.8   56.8   54.6   23.5   12.2   10.8 
 5   56.8   54.6   23.5   12.2    5.8 
 5  125.6   38.4   25.2    6.3    4.6 
 4   51.2   35.6   23.9    3.7 
 3   51.2   35.6   23.9 
 3  111.5   34.9   12.1 
 3    5.6    5.1    3.5 
 2   34.9   12.1 
 2   88.8    0.5 
 2  384.5    2.9 
 1   88.8 
 */
