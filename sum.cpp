/*
 Amy Ghotra
 CSCI 135
 Professor Maryash
 Project 1A : this project takes an input of a series of numbers and adds them up
 */

#include <iostream>
using namespace std;

int main()
{
    int s;
    int total = 0;
    while(cin >> s){
        total = total + s;
        //cout << s << " " << total << endl;
    }
    cout << total;
    return 0;
}
