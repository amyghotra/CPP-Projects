/*
 program asks for an integer input and outputs the next twin prime
 */

#include <iostream>
#include <cmath>
using namespace std;

// funtion checks if number is prime
bool isprime(int n)
{
    int i;
    int counter = 0;
    bool is_prime;
    int prime_number = 0;
    
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            counter++;
        }
    }
    if (counter > 2 || n <= 1) {
        is_prime = false;
    }
    else {
        is_prime = true;
        prime_number = i;
    }
    return is_prime;
}


// checks if number is a twin prime
bool isTwinPrime(int n)
{
    bool truth = false;
    bool is_n = isprime(n);
    int other = n + 2;
    
    if (is_n) {
        bool others = isprime(other);
        if (others) {
            truth = true;
        }
        else {
            other = n - 2;
            bool others = isprime(other);
            if (others) {
                truth = true;
            }
        }
    }
    
    return truth;
}

// function prints out the next twin prime
int nextTwinPrime(int n)
{
    int primetwin;
    int i = n;
    bool is_i_twin = false;
    bool isprev = false;
    bool isnext = false;
    
    // while the current number is not a twin prime, add +1 to the cuurent value of i
    while (is_i_twin != true) {
        i += 1;
        is_i_twin = isTwinPrime(i);     // calls the above function with the current value of i
        if (is_i_twin) {
            primetwin = i;              // if the current value of i is a twin prime, then store the value into a vairable
        }
    }
    
    return primetwin;                   // return the variable with the stored twin prime
}




int main()
{
    int y;
    cin >> y;
    
    int next_one = nextTwinPrime(y);
    
    cout << next_one;
    
    
    return 0;
}




