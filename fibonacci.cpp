/*
 Author: amy ghotra
 Course: CSCI-136
 Instructor: maryash
 Assignment: lab2c
 
 This program: Fibonacci Numbers with Loops and Arrays
 */

#include <iostream>
using namespace std;
//#include <cmath>

int main()
{
    int fib[60];
    fib[0] =0;
    fib[1] = 1;
    int i;
    cout << fib[0] << endl;
    cout << fib[1] << endl;
    for (i = 2; i<=60; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        cout << fib[i] << endl;
    }
    
    return 0;
}
