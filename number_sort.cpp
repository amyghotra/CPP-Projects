/*
 program sorts numbers
 
 
 */

#include <iostream>
using namespace std;

void sort3(int& a, int &b, int& c){
    
    // create values to store info to be used and re-stored later
    int largest;
    int middle;
    int smallest;
    
    // conditionals
    if (a > b && b > c) {
        largest = a;
        middle = b;
        smallest = c;
        a = smallest;
        b = middle;
        c = largest;
    }
    else if(a > b && b < c && a > c){
        smallest = b;
        middle = c;
        largest = a;
        a = smallest;
        b = middle;
        c = largest;
    }
    else if(a > b && b < c && a < c){
        smallest = b;
        middle = a;
        largest = c;
        a = smallest;
        b = middle;
        c = largest;
    }
    else if(a < b && b < c){
        smallest = a;
        b = b;
        largest = c;
        a = smallest;
        c = largest;
    }
    else if(a < b && b > c && a > c){
        smallest = c;
        largest = b;
        middle = a;
        a = smallest;
        b = middle;
        c = largest;
    }
    else if(a < b && b > c && a < c){
        smallest = a;
        largest = b;
        middle = c;
        a = smallest;
        b = middle;
        c = largest;
    }
    else if (a == b && b < c){
        largest = c;
        middle = b;
        smallest = a;
        a = smallest;
        b = middle;
        c = largest;
    }
    else if (a == b && b > c){
        largest = a;
        middle = b;
        smallest = c;
        a = smallest;
        b = middle;
        c = largest;
    }
    else if (a == b && b == c){
        largest = a;
        middle = b;
        smallest = c;
        a = smallest;
        b = middle;
        c = largest;
    }
    else if (a > b && b == c){
        largest = a;
        middle = b;
        smallest = c;
        a = smallest;
        b = middle;
        c = largest;
    }
    else if (a < b && b == c){
        largest = c;
        middle = b;
        smallest = a;
        a = smallest;
        b = middle;
        c = largest;
    }
    else {
        cout << " ... " << endl;
    }
    
    // there is no return statement because void functions dont return anything to their callers
}

// main function
int main()
{
    // numbers to be sorted
    int v = 3;
    int w = 4;
    int x = 1;
    
    /* To sort values inputted by the user, you would use the following bit of code instead of the one with the variables already declared
     int v;
     int w;
     int x;
     cin >> v;
     cin >> w;
     cin >> x;
     */
    
    // call the sort3 function
    sort3(v, w, x);
    
    // print the output: the numbers in ascending order
    cout << v << " " <<  w << " " << x << endl;
    
    return 0;
}
