/*
 Amy ghotra
 Prof Maryash
 Project 1C

*/

#include <iostream>
using namespace std;

// main function
int main()
{
    // variables which will be needed + used
    int number;
    char operators;
    int sum = 0;
    int i;
    // set sum == the first number that is inputted
    cin >> sum; // set sum equal to first number of input
   
    // while loop
    while (cin >> operators) // take the next character
    {
        cin >> number;  // take the next number
        if (operators == '+')
        {
            sum = sum + number;
        }
        else if (operators == ';')
        {
            cout << sum << endl;
            sum = number; // set first numbner of the next line equal to sum
        }
        else
        {
            sum = sum - number;
        }
    }

    //cout << sum << endl;
    
    return 0;
}

