/*
 this program will ask the user for a date and will output the day

*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int d;
    int year;
    int mm;
    int first = (25 * (mm + 1)) / 10;
    int second = (5 * (year % 100)) / 4;
    int third = (21 * (year / 100))/4;
    int w = (d + 5 + first + second + third) % 7;
    
    cout << "enter date: ";
    cin >> mm >> d >> year;
    cout << w;
    
    if (w == 0) {
        cout << " Monday" << endl;
    }
    else if (w == 1){
        cout << " Tueday" << endl;
    }
    else if (w == 2){
        cout << " Wednesday" << endl;
    }
    else if (w == 3){
        cout << " Thursday" << endl;
    }
    else if (w == 4){
        cout << " Friday" << endl;
    }else if (w == 5){
        cout << " Saturday" << endl;
    }
    else{
        cout << " Sunday" << endl;
    }
    
    
    return 0;
}
