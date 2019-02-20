/*
 Amy Ghotra
 Prof Maryash
 Lab 4C
*/

#include <iostream>
using namespace std;

int main()
{
    // vars
    int row; // rows == size aka the height
    int col; // cols == width
    int size;
    int width;
    
    // inputs
    cout << "Input size: ";
    cin >> size;
    width = size;
    
    // loops
    for (row = 1; row <= size; row++) {
        cout << endl;
        for (col = 1; col <= width; col++) {
            if ((col == row) || (col == width - (row -1))) {// this is what creates the cross
                cout << "*";
            }
            else{
                cout << " "; // comments spaces whereever the rows != cols ; this is what essentially creates the diagonal line
            }
        }
    }
    
    
    return 0;
}
