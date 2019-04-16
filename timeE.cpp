// amy ghotra
// program will determine if two timeslots overlap

#include <iostream>
using namespace std;

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

// class for time
class Time {
public:
    int h;
    int m;
};

class Movie {
public:
    string title;
    Genre genre;
    int duration;
};

class TimeSlot {
public:
    Movie movie;
    Time startTime;
};

//function prototypes
int minutesSinceMidnight(Time time); // return number minutes from 0:00AM until givn time
int minutesUntil(Time earlier, Time later); // difference btwn times
Time addMinutes(Time time0, int min); // get the end time given the start time and duration
bool timeOverlap(TimeSlot ts1, TimeSlot ts2); // see if timeslots overlap

int main()
{
    Time first_movie;
    cin >> first_movie.h >> first_movie.m;
    
    Time second_movie;
    cin >> second_movie.h >> second_movie.m;
    
    Movie movie1 = {"The Wolf of Wall Street", COMEDY, 180};
    Movie movie2 = {"5 Centimeters Per Second", DRAMA, 63};
    
    TimeSlot morning = {movie1, {first_movie.h, first_movie.m}};
    TimeSlot daytime = {movie2, {second_movie.h, second_movie.m}};
    //TimeSlot evening = {movie1, {16, 10}};
    
    bool over = timeOverlap(morning, daytime);
    cout << over << endl;
    
    return 0;
}

// function to see if timeslots overlap
bool timeOverlap(TimeSlot ts1, TimeSlot ts2)
{
    bool overlap = false;
    
    Time first_start = ts1.startTime;
    int first_length = ts1.movie.duration;
    Time first_end = addMinutes(first_start, first_length); // get the end time of the first
    
    Time second_start = ts2.startTime;
    int second_length = ts2.movie.duration;
    Time second_end = addMinutes(second_start, second_length); // get the end time of the second
    
    // difference between the first and second movie start times
    int diff = minutesUntil(first_start, second_start);
    
    //cout << "first end: " << first_end.h << ":" << first_end.m << endl;
    //cout << "second end: " << second_end.h << ":" << second_end.m << endl;
    
    if (first_start.h == second_start.h) {
        overlap = true;
        return overlap;
    }
    // if the second movie starts before the first one
    if (second_start.h < first_start.h) {
        // check if the second movie ends before or after the first one
        if (second_end.h > first_start.h) {
            overlap = true;
            return overlap;
        }
        if (second_end.h < first_start.h) {
            overlap = false;
            return overlap;
        }
        if (second_end.h == first_start.h) {
            if (second_end.m > first_start.m) {
                overlap = true;
                return overlap;
            }
        }
    }
    // if the first movie starts before the second one
    if (first_start.h < second_start.h) {
        // if the first one ends after the second one starts
        if (first_end.h > second_start.h) {
            overlap = true;
            return overlap;
        }
        if (first_end.h == second_start.h) {
            if (first_end.m > second_start.m) {
                overlap = true;
                return overlap;
            }
        }
        if (first_end.h < second_start.h) {
            overlap = false;
            return overlap;
        }
    }
    
    
    return overlap;
}

// funtion returns how much time between the two input times
int minutesUntil(Time earlier, Time later)
{
    int minutes;
    int first_hour = earlier.h * 60;
    int first_total = first_hour + earlier.m;
    int second_hour = later.h * 60;
    int second_total = second_hour + later.m;
    
    minutes = second_total - first_total;
    
    return minutes;
}


// get movie end time given original time and minutes being added to current time
Time addMinutes(Time time0, int min)
{
    Time moment;
    int counter = 0;
    int total_min = time0.m + min;
    while (total_min >= 60) {
        counter++;
        total_min -= 60;
    }
    int hour = counter;
    int total_hours = time0.h + hour;
    moment.h = total_hours;
    moment.m = total_min;
    
    return moment;
}




