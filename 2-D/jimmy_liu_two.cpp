//This program demonstrates a two-dimensional array.
//Part 2 - make it more general (use functions)

// Jimmy (Sicong) Liu
#include <iostream>

using namespace std;

const int ROWS = 30;         // maximum number of rows
const int COLS = 40;         // maximum number of columns

void displayTable(double table[][COLS], int, int);


int main()
{

    double table[ROWS][COLS]=   //Array with 3 ROWS and 4 COLumnS
    {
        {1, 9, 5, 3},
        {2, 4, 6, 8},
        {3, 5, 8, 7}
    };  // initializing the array


    displayTable (table, 3, 4);

    return 0;
}

// This function displays a 2D array row by row
// Input parameter: table[][COLS]
void displayTable(double table[][COLS], int row, int col) //ROW is not needed
{
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            cout << table[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


/* OUTPUT
 
 MacBook-Pro-2:2-D jimmyliu$ ./a.out
 1 9 5 3
 2 4 6 8
 3 5 8 7


Process returned 0 (0x0)   execution time : 0.109 s
Press any key to continue.
*/
