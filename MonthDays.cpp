/*
 Author: Amy Ghotra
 Description: program gets month and year from user and prints out how many days are in that month
 */

#include <iostream>
using namespace std;

//main fucntion:
int main()
{
    // variables:
    int inputMonth;
    string month;
    int inputYear;
    int days = 0;
    string yearType;
    
    cout << "Enter year: ";        // asking the user for an input
    cin >> inputYear;                // saving the input into a var
    cout << "Enter month: ";    // asking the user for an input
    cin >> inputMonth;            // saving the input into a var
    
    // conditionals to determine how many days  
    if (inputMonth == 1){
        month = "January";
        days = 31;
    }
    else if (inputMonth == 2){
        month = "February";
        // need extra code because of leap years
        if (inputYear % 4 != 0){
            yearType = "Common year";
            days = 28;
        }
        else if (inputYear % 100 != 0) {
            yearType = "Leap year";
            days = 29;
        }
        else if (inputYear % 400 != 0){
            yearType = "Common year";
            days = 28;
        }
        else {
            yearType = "Leap year";
            days = 29;
        }
    }
    // continue on with the months
    else if (inputMonth == 3){
        month = "March";
        days = 31;
    }
    else if (inputMonth == 4){
        month = "April";
        days = 30;
    }
    else if (inputMonth == 5){
        month = "May";
        days = 31;
    }
    else if (inputMonth == 6){
        month = "June";
        days = 30;
    }
    else if (inputMonth == 7){
        month = "July";
        days = 31;
    }
    else if (inputMonth == 8){
        month = "August";
        days = 31;
    }
    else if (inputMonth == 9){
        month = "September";
        days = 30;
    }
    else if (inputMonth == 10){
        month = "October";
        days = 31;
    }
    else if (inputMonth == 11){
        month = "November";
        days = 30;
    }
    else if (inputMonth == 12){
        month = "December";
        days = 31;
    }
    else {
        cout << "invalid input";
    }
    // print out the number of days in th given month of a given year
    cout << days;
    return 0;
}
