/*
 Author: Amy Ghotra
 */

#include <iostream>
using namespace std;

//main fucntion:
int main()
{
    //variables:
    int numberOne = 0;
    int numberTwo = 0;
    int numberThree = 0;
    int smaller = 0;
 
    // get input/numbers from user and store them into variables
    cout << "Enter the first number: ";
    cin >> numberOne;
    cout << "Enter the second number: ";
    cin >> numberTwo;
    cout << "Enter the third number: ";
    cin >> numberThree;
 
    // use conditionals to place them in order
    if ((numberOne < numberTwo) && (numberOne < numberThree)) {
        smaller = numberOne;
    }
    else if ((numberTwo < numberOne) && (numberTwo < numberThree)) {
        smaller = numberTwo;
    }
    else if ((numberThree < numberOne) && (numberThree < numberTwo)) {
        smaller =  numberThree;
    }
    
    // print out the smallest number
    cout << "The smaller of the three is " << smaller;
 
    return 0;
}
