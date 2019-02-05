/*
 Author: amy ghotra
 Course: CSCI-136
 Instructor: maryash
 Assignment: lab2a
 
 This program prompts the user to input an integer between 1 and 99.
 */

#include <iostream>
using namespace std;

int main()
{
    int user_input;
    int sqrd;
    cout << "Enter an integer 0 < n < 100";
    cin >> user_input;
    while (user_input >= 100 || user_input <= 0 ) {
        cout << "Please re-enter";
        cin >> user_input;
    }
    if (user_input > 0 && user_input < 100) {
        sqrd = user_input * user_input;
        cout << "Number squared is " << sqrd;
    }
    return 0;
}
