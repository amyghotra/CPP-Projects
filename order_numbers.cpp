/*
 this program will put numbers in order
 
*/

#include <iostream>
using namespace std;

void sort(int& a, int &b){  // "&" = reference parameter: used to change the value of an argument
    
    int newletter;          // create a new variable in order to store new value
    
    if (a > b) {            // if the first number is larger than the second
        newletter = b;      // store the value of b into the variable created earlier
        b = a;              // variable b will now be assigned the value of a
        a = newletter;      // variable a will be assigned the value of newletter, or, the original b
    }
    else {                  // if the first number < second number then the numbers will remain as they are
        a = a;
        b = b;
    }
    
    // there is no return statement because void functions dont return anything to their callers
}

int main()
{
    // to sort given values:
    int u = 2;
    int v = 3;
    int w = 4;
    int x = 1;
    
    /* To sort values inputted by the user, you would use the following bit of code instead of the one with the variables already declared
     int u;
     int v;
     int w;
     int x;
     cin >> u;
     cin >> v;
     cin >> w;
     cin >> x;
     */
    
    // call the void function:
    sort(u,v);
    sort(w,x);
    
    // print out the numbers in their new orders
    cout << u << " " << v << endl;
    cout << w << " " << x << endl;
    
    return 0;
}
