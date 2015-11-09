// Homework One
// Jimmy (Sicong) Liu 20076260
// CIS 22B
// September 27th 2015
// XCode 7.0

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
string getProdNum();
int binarySearch (const string [], int, string);
void displayProd(const double [], int, const string[]);
void writeToFile(const string[], int);
void printThisLine();


int main()
{
    // Variable initializatoin
    string names[100];
    double gpa[100];
    string notFound[100];
    int notFoundCounter = 0;
    
    // Reading in text file to array names
    string name;
    double value;
    ifstream myfile("names.txt", ifstream::in);
    int arrayCounter = 0;
    while(myfile >> value >> name) {
        if (arrayCounter < 100) {
            gpa[arrayCounter] = value;
            names[arrayCounter] = name;
            arrayCounter++;
        } else {
            printThisLine();
            break;
        }
    }
    
    string prodNum;	// To hold a product number
    int index;		// To hold search results
    char again;		// To hold a Y or N answer
    
    do
    {
        // Get the desired product number.
        prodNum = getProdNum();
        
        // Search for the product number.
        index = binarySearch(names, arrayCounter, prodNum);
        
        // Display the results of the search.
        if (index == -1) {
            cout << "That student was not found.\n";
            notFound[notFoundCounter] = prodNum;
            notFoundCounter++;
        }
        else
            displayProd(gpa, index, names);
        
        // Does the user want to do this again?
        cout << "Would you like to look up another student? (y/n) ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    writeToFile(notFound, notFoundCounter);
    return 0;
}

// Get the name of the student from user input
string getProdNum()
{
    string prodNum; // Product number
    
    cout << "Enter the student's name: ";
    cin >> prodNum;
    return prodNum;
}

// Does all the binary searching
int binarySearch(const string array[], int numElems, string value)
{
    int first = 0,			 // First array element
    last = numElems - 1, // Last array element
    middle,				 // Midpoint of search
    position = -1;		 // Position of search value
    bool found = false;		 // Flag
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;  // Calculate midpoint
        if (array[middle] == value)	  // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;			// If value is in upper half
    }
    return position;
}

// Print name and GPA of student requested
void displayProd(const double gpa[], int index, const string names[])
{
    cout << "Name: " << names[index] << "\n";
    cout << "GPA: " << gpa[index] << endl;
}

// Write the missing student names to a file
void writeToFile(const string names[], int count) {
    ofstream outputFile ("missingNames.text");
    if (outputFile.is_open()) {
        for (int j = 0; j < count; j++) {
            outputFile << names[j] + "\n";
        }
        outputFile.close();
    } else {
        cout << "Unable to create file to write missing names";
    }
}

// Call this function when file is more than 100 lines
void printThisLine() {
    cout << "The file contains more than 100 lines!\n";
}

/*
Output:
 
 MacBook-Pro-2:test jimmyliu$ ./a.out
 Enter the student's name: Adam
 Name: Adam
 GPA: 2
 Would you like to look up another student? (y/n) y
 Enter the student's name: Clare
 Name: Clare
 GPA: 3.9
 Would you like to look up another student? (y/n) y
 Enter the student's name: Jimmy
 That student was not found.
 Would you like to look up another student? (y/n) y
 Enter the student's name: Stephen
 That student was not found.
 Would you like to look up another student? (y/n) n
*/