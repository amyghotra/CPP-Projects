// amy ghotra
// program will schedule a movie to start as soon as another ends

#include <iostream>
using namespace std;

// enumeration for movie genre
enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

// class for time
class Time {
public:
    int h;
    int m;
};

// class for basic movie details
class Movie {
public:
    string title;
    Genre genre;
    int duration;
};

// class for movie time
class TimeSlot {
public:
    Movie movie;
    Time startTime;
};

//function prototypes
Time addMinutes(Time time0, int min);
void printMovie(Movie mv);
void printTimeSlot(TimeSlot ts);
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);

int main()
{
    
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    
    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {14, 10}};
    TimeSlot evening = {movie1, {16, 10}};
    
    // create new var of type TimeSlot and call function in order to set its value
    TimeSlot newSlot = scheduleAfter(morning, movie1);
    // print out the start time of the next movie
    cout << newSlot.startTime.h << ":" << newSlot.startTime.m << endl;
    
    
    return 0;
}

// schedule a movie to start right after another one ends
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    // find out when the first movie ends
    Time first_end = addMinutes(ts.startTime, ts.movie.duration);
    
    // create a new timeslot
    TimeSlot newSlot;
    // the start time will be when the first movie ended
    newSlot.startTime = first_end; // set the start time of the new movie to the end time of the first one
    
    // create new time slot for next movie
    TimeSlot newMovie;
    // the movie will start when the first ends
    newMovie.startTime = first_end;
    newMovie.movie = nextMovie;
    
    return newMovie;
}


// get movie end time given original time and minutes being added to current time
Time addMinutes(Time time0, int min)
{
    Time moment; // new time
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




