// amy ghotra
// scheduling time slots for a movie theatre
// program prints out movie details along with its start and end time

#include <iostream>
using namespace std;

// enumeration list for movie genres
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

// class for time
class Time {
public:
    int h;
    int m;
};

// class for containing basic movie details
class Movie {
public:
    string title;
    Genre genre;
    int duration;
};

// class for movie timeslot
class TimeSlot {
public:
    Movie movie;
    Time startTime;
};

//function prototypes
Time addMinutes(Time time0, int min);
void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);

int main()
{
    // movies
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    
    // timeslots
    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot evening = {movie2, {16, 45}};
    
    
    // call function
    printTimeSlot(morning);
    
    return 0;
}


// prints out the start time and end time
void printTimeSlot(TimeSlot ts)
{
    // get the end time by calling another function
    Time moment = addMinutes(ts.startTime, ts.movie.duration);
    printMovie(ts.movie);
    // print out the start and end times
    cout << "[starts at " << ts.startTime.h << ":" << ts.startTime.m  << ", ends by "<< moment.h << ":" << moment.m << "]";
}


// outputs movie title, genre, and run time
void printMovie(Movie mv){
    string g;
    // find out what the genre of the movie is:
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

// get final/end time given original time and duration
Time addMinutes(Time time0, int min)
{
    Time moment; // new time
    int counter = 0;
    int total_min = time0.m + min;
    while (total_min >= 60) { // if this is larger than 60 than that is = to an hour
        counter++; // keep track of the hours
        total_min -= 60; // subtract 60
    }
    int hour = counter;
    int total_hours = time0.h + hour;
    moment.h = total_hours;
    moment.m = total_min;
    
    return moment;
}
