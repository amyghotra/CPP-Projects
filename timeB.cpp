// amy ghotra
// user prompted for time and minutes
// minutes will be added to the time and the new time is printed

#include <iostream>
using namespace std;

// class for time
class Time {
public:
    int h;
    int m;
};

//function prototype
Time addMinutes(Time time0, int min); // add minutes to a given time

int main()
{
    // get user input
    // get and store the original time
    cout << "Enter first time: ";
    int firstHour;
    int firstMinute;
    cin >> firstHour >> firstMinute;
    // get and store the minutes the user wishes to add to the original time
    cout << "minutes: ";
    int minutes;
    cin >> minutes;
    
    // put input into Time type variable
    Time first = {firstHour , firstMinute};
    
    // create new variable of type Time
    // set the value of the variable to the return value of a function
    Time moment = addMinutes(first, minutes);
    cout << moment.h << " " << moment.m << endl; // print out the final time (original + minutes)
    
    
    return 0;
}


Time addMinutes(Time time0, int min)
{
    Time moment; // create new time
    int counter = 0;
    int total_min = time0.m + min;
    while (total_min >= 60) { // is this is larger than 60 then that is = to an hour
        counter++; // keep track of hours
        total_min -= 60; // subtract hours
    }
    int hour = counter;
    int total_hours = time0.h + hour;
    moment.h = total_hours;
    moment.m = total_min;
    
    return moment;
}
