/*
 Amy Ghotra
 */

#include <iostream>
using namespace std;

int main()
{
    int numberOne;
    int numberTwo;
    int larger = 0;
    int smaller = 0;
    cout << "Enter a number";
    cin >> numberOne;
    cout << "Enter another number";
    cin >> numberTwo;
    if (numberOne > numberTwo) {
        larger = numberOne;
        smaller = numberTwo;
    }
    else if (numberTwo > numberOne){
        larger = numberTwo;
        smaller = numberOne;
    }
    else{
        cout << "invalid input(s)";
    }
    cout << "The smaller of the two is: " << smaller << endl;
    return 0;
}

