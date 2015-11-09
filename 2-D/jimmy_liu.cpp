//This program demonstrates a two-dimensional array.
//Part 1 - define, initialize, access, display

// Jimmy (Sicong) Liu
#include <iostream>

using namespace std;

const int ROWS = 3;         // maximum number of rows
const int COLS = 4;         // maximum number of columns

int main()
{

    double table[ROWS][COLS]=   //Array with 3 ROWS and 4 COLumnS
    {
        {10, 90, 50, 30},
        {20, 40, 60, 80},
        {35, 55, 85, 75}
    };  // initializing the array

    // Display the first element in the first row
    cout << table[0][0] << "\n";
    // Display the last element in the last row
    cout << table[2][3] << "\n";
    // Display the second element in the first row
    cout << table[0][1] << "\n";
    // Use bad indicies
    cout << table[5][10] << "\n";
    // row  = 0; col = 4;
    cout << table[0][4] << "\n";
    cout << endl;
    // write code to dispaly the first row
    for (int i = 0; i < COLS; i++) {
        cout << table[0][i] << " ";
    }
    cout << endl;cout << endl;
    // write code to display the first row
    for (int j = 0; j < ROWS; j++) {
        cout << table[j][0] << "\n";
    }
    cout << endl;
    // print entire table row
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
    
    // print entire table column
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
    return 0;
}



/* OUTPUT
 
 MacBook-Pro-2:2-D jimmyliu$ ./a.out
 10
 75
 90
 6.95322e-310
 20
 
 10 90 50 30
 
 10
 20
 35
 
 10 90 50 30
 20 40 60 80
 35 55 85 75
 
 10 20 35
 90 40 55
 50 60 85 
 30 80 75

Process returned 0 (0x0)   execution time : 0.109 s
Press any key to continue.
*/
