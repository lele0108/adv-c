// Demetris Leadership Center (DLC) product lookup program
// This program allows the user to enter a product number
// and then displays the title, description, and price of
// that product.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function prototypes
string getProdNum();
int binarySearch (const string [], int, string);
void displayProd(const double [], int);


int main()
{
    // Variable initializatoin
    string names[100];
    double gpa[100];
    
    // Reading in text file to array names
    string name;
    double value;
    ifstream myfile("names.txt", ifstream::in);
    int arrayCounter = 0;
    while(myfile >> value >> name) {
        gpa[arrayCounter] = value;
        names[arrayCounter] = name;
        arrayCounter++;
    }
    
    /*for (int i = 0; i < arrayCounter; i++) {
        cout << "Name: " << names[i];
        cout << " GPA: " << gpa[i] << endl;
    }*/
    
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
        if (index == -1)
            cout << "That student was not found.\n";
        else
            displayProd(gpa, index);
        
        // Does the user want to do this again?
        cout << "Would you like to look up another student? (y/n) ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    return 0;
}

//***************************************************
// Definition of getProdNum function                *
// The getProdNum function asks the user to enter a *
// product number. The input is validated, and when *
// a valid number is entered, it is returned.       *
//***************************************************

string getProdNum()
{
    string prodNum; // Product number
    
    cout << "Enter the student's name: ";
    cin >> prodNum;
    // Validate input
    /*while (prodNum < MIN_PRODNUM || prodNum > MAX_PRODNUM)
    {
        cout << "Enter a number in the range of " << MIN_PRODNUM;
        cout <<" through " << MAX_PRODNUM << ".\n";
        cin >> prodNum;
    }*/
    return prodNum;
}

//***************************************************************
// Definition of binarySearch function                          *
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of numElems        *
// elements, is searched for the number stored in value. If the *
// number is found, its array subscript is returned. Otherwise, *
// -1 is returned indicating the value was not in the array.    *
//***************************************************************

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

//************************************************************
// The displayProd function accepts three arrays and an int. *
// The arrays parameters are expected to hold the title,     *
// description, and prices arrays defined in main. The index *
// parameter holds a subscript. This function displays the   *
// information in each array contained at the subscript.     *
//************************************************************

void displayProd(const double gpa[], int index)
{
    cout << "GPA: " << gpa[index] << endl;
}