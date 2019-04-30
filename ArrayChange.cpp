/*
 Author: amy ghotra
 
 This program starts off with an array full of 1's
 The user is prompted to input a new index value, and is also prompted to assign 
 the index value associated with the array a new value
 The prgram outputs updates and prints arrays
 */

#include <iostream>
using namespace std;
//#include <cmath>

int main()
{
    int myData[10]; // create array
    int i;
    int new_index;
    int new_value;
   
    // change every value in the array to be 1
    for (i = 0; i <= 10; i++) {
        myData[i] = 1;
    }
 
    // replace values with values given by user
    do {
        for (i = 0; i <= 10; i++) {
            cout << myData[i];
        }
        cout << "Input index";
        cin >> new_index;
        if (new_index >= 0 && new_index < 10) {
            myData[new_index] = new_value;
            cout << "Input value";
            cin >> new_value;
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

