// amy ghotra

#include <iostream>
using namespace std;

// class for time
class Time {
public:
    int h; // hour
    int m; // minute
};

//function prototypes
void printTime(Time time); // print time in "hour:minute" format
int minutesSinceMidnight(Time time); // return number minutes from 0:00AM until givn time
int minutesUntil(Time earlier, Time later); // difference btwn two given times

int main()
{
    // get user input for times
    cout << "Enter first time: ";
    int firstHour;
    int firstMinute;
    cin >> firstHour >> firstMinute;
    cout << "Enter second time: ";
    int secondHour;
    int secondMinute;
    cin >> secondHour >> secondMinute;
    
    // put input into Time type variables
    Time first = {firstHour , firstMinute};
    Time second = {secondHour, secondMinute};
    
    // call functions and print out their returned values
    cout << minutesUntil(first, second) << endl; // minutes between first and second time
    
    cout << minutesSinceMidnight(first) << endl; // minutes since midnight
    
    return 0;
}

// function to print time with colon ":"
void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

// function returns the number of minutes since midnight
int minutesSinceMidnight(Time time)
{
    // variable to store minutes
    int since;
    
    // set time for midnight
    Time midnight;
    midnight.h = 0;
    midnight.m = 0;
    
    // turn the hours into minutes (ex: 6 turns into 360)
    int hour_to_minute = (time.h)*60;
    // add the minutes to the hour_to_minute (ex: if time == 6:06 then since = 6 + 360)
    since = (time.m) + hour_to_minute;
    
    return since;// return the number of minutes
}

// funtion returns how much time between the two input times
int minutesUntil(Time earlier, Time later)
{
    int minutes; // to hold the minutes btwn the two times
    int first_hour = earlier.h * 60; // turn the hour of the first time into minutes (ex: 2 will = 120)
    int first_total = first_hour + earlier.m; // add the minutes of the first time to the first hour minutes
    // do the same for the second hour:
    int second_hour = later.h * 60;
    int second_total = second_hour + later.m;
    
    // get the difference btwn the two times
    minutes = second_total - first_total;
    
    
    
    return minutes;
}
