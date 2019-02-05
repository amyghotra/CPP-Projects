/*
 Author: Amy Ghotra
 Course: CSCI-136
 Instructor: Maryash
 Assignment: Lab1C
 
 Program asks user for three year and prints if it's a common or leap year
 */

#include <iostream>
using namespace std;

// main function:
int main()
{
    int inputYear = 0;
    string yearType;
    cout << "Enter a year ";
    cin >> inputYear;
    if (inputYear % 4 != 0){
        yearType = "Common year";
    }
    else if (inputYear % 100 != 0) {
        yearType = "Leap year";
    }
    else if (inputYear % 400 != 0){
        yearType = "Common year";
    }
    else {
        yearType = "Leap year";
    }
    cout << yearType;
    return 0;
}
