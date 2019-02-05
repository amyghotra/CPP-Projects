/*
 Author: amy ghotra
 Course: CSCI-136
 Instructor: maryash
 Assignment: lab2c
 
 This program starts off with an array full of 1's
 The user is prompted to input a new index value, and is also prompted to assign the index value associated with the array a new value
 The prgram outputs updates and prints arrays
 */

#include <iostream>
using namespace std;
//#include <cmath>

int main()
{
    int myData[10];
    int i;
    int new_index;
    int new_value;
    for (i = 0; i <= 10; i++) {
        myData[i] = 1;
    }
    do {
        for (i = 0; i <= 10; i++) {
            cout << myData[i] << " ";
        }
        cout << endl << "Input index ";
        cin >> new_index;
        if (new_index >= 0 && new_index < 10) {
            cout << "Input value ";
            cin >> new_value;
            myData[new_index] = new_value;
        }

        else if (new_index >= 10 || new_index < 0) {
            cout << "Index out of range. Exit.";
        }
        else {
            cout << "hello this is some random text";
        }
        
    } while(new_index >= 0 && new_index < 10);
    
    return 0;
}


