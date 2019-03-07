/*
 ß program will prompt the user for various pieces of information before calculating how much money the individual will have after a given amount of years
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double initial;
    double interest;
    int years;
    
    cout << "Enter intial value: xs";
    cin  >> initial;
    cout << "Enter interest rate: ";
    cin >> interest;
    cout << "Enter years: ";
    cin >> years;
    
    if (interest > 1.0) {
        interest =  interest / 100;
    }
    else {
        interest = interest;
    }
    
    double balance = initial * pow((1 + interest), years);
    
    cout << "Balance after " << years << " years is: " << balance;
    
    
    
    return 0;
}
