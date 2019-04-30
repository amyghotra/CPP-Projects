/*
 Author: amy ghotra
 
 This program asks the user for two numbers, which then become the upper and lower limits. 
 The program then goes on to output all numbers between and including the limits
 */

#include <iostream>
using namespace std;

int main()
{
    // variables to store the limits
    int first_input;
    int second_input;
    int U;
    int L;
    int i;
    // get limits from user
    cout << "Enter a number ";
    cin >> first_input;
    cout << "Enter another numnber ";
    cin >> second_input;
    // ensure that the first limit is the upper limit and the second input is the lower limit
    if (first_input > second_input) {
        U = first_input;
        L = second_input;
    }
    else {
        U = second_input;
        L = first_input;
    }
    // use for loop to print out the numbers
    for (int i = L; i < U; i++) {
        cout << i << endl;
    }
    return 0;
}
