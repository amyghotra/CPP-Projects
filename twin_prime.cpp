/*
  program determines if a number is a twin prime ( if prime number + or - 2 is also prime then prime number = twin prime)
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

// function determines of prime is a twin prime
bool isTwinPrime(int n)
{
    bool truth = false;
    bool is_n = isprime(n);                     // check to see if the inputted integer is a prime number
    int other = n + 2;
    
    if (is_n) {                                  // if the user inputted number is prime
        bool others = isprime(other);        // check to see if n + 2 is also prime
        if (others) {                        // if n + 2 is prime
            truth = true;                   // then the inputted integer is twin prime
        }
        else {
            other = n - 2;                   // if n + 2 != prime then check to see if n - 2 is prime
            bool others = isprime(other);
            if (others) {                   // if n - 2 is prime
                truth = true;               // then the inputted integer is a twin prime
            }
        }
    }
    
    return truth;
}


// main function
int main()
{
    int y;
    cin >> y;
    
    cout << isTwinPrime(y);
    
    
    return 0;
}

