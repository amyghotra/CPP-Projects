/*
 Author: amy ghotra
 Course: CSCI-136
 Instructor: maryash
 Assignment: lab2b
 
 This program asks the user for two numbers, which then become the upper and lower limits. The program then goes on to out put all numbers between and including the limits
 */

#include <iostream>
using namespace std;

int main()
{
    int first_input;
    int second_input;
    int U;
    int L;
    int i;
    cout << "Enter a number ";
    cin >> first_input;
    cout << "Enter another numnber ";
    cin >> second_input;
    if (first_input > second_input) {
        U = first_input;
        L = second_input;
    }
    else {
        U = second_input;
        L = first_input;
    }
    for (int i = L; i < U; i++) {
        cout << i << endl;
    }
    return 0;
}
