/*
 Author: Amy Ghotra
 Description: 
 */

#include <iostream>
using namespace std;

// main function:
int main()
{
    int inputYear; // use to store the year
    string yearType;
    cout << "Enter a year ";
    cin >> inputYear; // store year provided by user into variable
 
    // use conditionals to find leap year
    if (inputYear % 4 != 0){  
        yearType = "Common year";
        // if it is not divisible by 4 then it is not a leap year
    }
    else if (inputYear % 100 != 0) {
        yearType = "Leap year";
        // if it is not divisible by 100 it is not a leap year
    }
    else if (inputYear % 400 != 0){
        yearType = "Common year";
        // if it is not divisible by 400 it is not a leap year
    }
    else {
        yearType = "Leap year";
        
    }
 
    // print out whether it is a leap year or a common year
    cout << yearType;
 
    return 0;
}
