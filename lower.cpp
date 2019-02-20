/*
 Amy Ghotra
 Prof Maryash
 Lab 4D: lower triangle
 */

#include <iostream>
using namespace std;

// main function
int main()
{
    // variables
    int input_size;
    int j;
    int i;
    
    //get input from user pertaining to height
    cout << "Input size :";
    cin >> input_size;
    
    // for loop to draw out triangle
    for (i = 1; i <= input_size; i++) {
        cout << endl;
        for (j = 1; j <= i; j++) {
            cout << "*";
        }
    }
    
    return 0;
}
