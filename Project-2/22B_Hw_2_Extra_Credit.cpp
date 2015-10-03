/**
    Extra Credit - Homework 2

 	Among n persons, a celebrity is defined as someone who is known by everyone
    but does not know anyone. The problem is to identify the celebrity,
    if one exits.

    Your task is to write two functions and call them from main().
    •	The first function is to display the table and the names in a readable format. (reuse)
    •	The second function is to identify the celebrity.

    Run the program 4 times and save each output as a comment, at the end of the source file
    // See the required 4 test cases below

    NOTE: Solving the problem with two nested loops is the straight forward solution; there is
    a more efficient solution that does not require nested loops.

	   Written by: Jimmy Liu
	   Date: Oct 3rd, 2015
*/
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_PEOPLE = 100;

void writeTable(const int[][MAX_PEOPLE], const string[], int);
void findPerson(const int[][MAX_PEOPLE], const string[], int);

int main (void)
{
//	Local Definitions
//  Test #1
/**
    int  n = 5;
    string names[MAX_PEOPLE] = {"Ami", "Bob", "Cal", "Dan", "Ion"};
	int  table[MAX_PEOPLE][MAX_PEOPLE] =
	{
	    {0,   1,   1,   1,   0},
	    {0,   0,   1,   0,   0},
        {0,   0,   0,   0,   0},
        {1,   0,   1,   0,   1},
        {0,   1,   1,   1,   0}
	};
*/
//  Test #2
/**
    int  n = 5;
    string names[MAX_PEOPLE] = {"Ami", "Bob", "Cal", "Dan", "Ion"};
	int  table[MAX_PEOPLE][MAX_PEOPLE] =
	{
	    {0,   1,   1,   1,   0},
	    {0,   0,   1,   0,   0},
        {0,   0,   0,   0,   0},
        {1,   0,   0,   0,   1},
        {0,   1,   1,   1,   0}
	};
*/

//  Test #3
/**
    int  n = 5;
    string names[MAX_PEOPLE] = {"Ami", "Bob", "Cal", "Dan", "Ion"};
	int  table[MAX_PEOPLE][MAX_PEOPLE] =
	{
	    {0,   1,   1,   1,   0},
	    {0,   0,   1,   0,   0},
        {0,   0,   0,   0,   1},
        {1,   0,   1,   0,   1},
        {0,   1,   1,   1,   0}
	};
*/


//  Test #4

    int  n = 8;
    string names[MAX_PEOPLE] = {"Ami", "Bob", "Cal", "Dan", "Ion", "Ada", "Tom", "Ann"};
	int  table[MAX_PEOPLE][MAX_PEOPLE] =
	{
	    {0,   1,   1,   1,   0,   1,   1,   0},
	    {0,   0,   1,   0,   0,   1,   1,   1},
        {0,   0,   0,   0,   0,   1,   0,   1},
        {1,   0,   1,   0,   1,   1,   0,   1},
        {0,   1,   1,   1,   0,   1,   1,   1},
        {0,   0,   0,   0,   0,   0,   0,   0},
	    {0,   0,   0,   0,   0,   1,   0,   1},
        {0,   0,   1,   0,   1,   1,   0,   0},
	};


//	Statements
    // call your functions below
    // write the name of the celebrity, or a message, such as "No celebrity!" in main()
    // Run the program 4 times and save each output as a comment, at the end of the source file


    writeTable(table, names, n);
    cout << endl;
    findPerson(table, names, n);
	return 0;
}	// main

void writeTable(const int storage[][MAX_PEOPLE], const string names[], int num) {
    for (int i = 0; i < num; i++) {
        if (i == 0) {
            cout << "    | ";
            for (int z = 0; z < num; z++)
                cout << names[z] << " ";
            cout << endl;
            cout << "---   ";
            for (int k = 0; k < num; k++)
                cout << "--- ";
            cout << endl;
        }
        cout << names[i] << " | ";
        for (int j = 0; j < num; j++) {
            cout << setw(3) << storage[i][j] << " ";
        }
        cout << endl;
    }
}

void findPerson(const int storage[][MAX_PEOPLE], const string names[], int num) {
    for (int j = 0; j < num; j++) {
        int count = 0;
        for (int i = 0; i < num; i++) {
            if (storage[i][j] == 1)
                count++;
        }
        if (count == num - 1) {
            bool match = true;
            for (int z = 0; z < num; z++) {
                if (storage[j][z] == 1)
                    match = false;
            }
            if (match) {
                cout << "The celebrity is " << names[j] << "." << endl;
                return;
            }
        }
    }
    cout << "No celebrity!" << endl;
}

/**
There are results:

First run:
MacBook-Pro-2:project-2 jimmyliu$ ./a.out
    | Ami Bob Cal Dan Ion 
---   --- --- --- --- --- 
Ami |   0   1   1   1   0 
Bob |   0   0   1   0   0 
Cal |   0   0   0   0   0 
Dan |   1   0   1   0   1 
Ion |   0   1   1   1   0 

The celebrity is Cal.

Second run: 
MacBook-Pro-2:project-2 jimmyliu$ ./a.out
    | Ami Bob Cal Dan Ion 
---   --- --- --- --- --- 
Ami |   0   1   1   1   0 
Bob |   0   0   1   0   0 
Cal |   0   0   0   0   0 
Dan |   1   0   0   0   1 
Ion |   0   1   1   1   0 

No celebrity!

Third run:
MacBook-Pro-2:project-2 jimmyliu$ ./a.out
    | Ami Bob Cal Dan Ion 
---   --- --- --- --- --- 
Ami |   0   1   1   1   0 
Bob |   0   0   1   0   0 
Cal |   0   0   0   0   1 
Dan |   1   0   1   0   1 
Ion |   0   1   1   1   0 

No celebrity!

Final run:
MacBook-Pro-2:project-2 jimmyliu$ ./a.out
    | Ami Bob Cal Dan Ion Ada Tom Ann 
---   --- --- --- --- --- --- --- --- 
Ami |   0   1   1   1   0   1   1   0 
Bob |   0   0   1   0   0   1   1   1 
Cal |   0   0   0   0   0   1   0   1 
Dan |   1   0   1   0   1   1   0   1 
Ion |   0   1   1   1   0   1   1   1 
Ada |   0   0   0   0   0   0   0   0 
Tom |   0   0   0   0   0   1   0   1 
Ann |   0   0   1   0   1   1   0   0 

The celebrity is Ada.

*/
