/*
 program asks the user for an integer and prints out the next prime number
 */


#include <iostream>
#include <cmath>
using namespace std;

// function to test if number is prime
bool isprime(int n){
    int i;
    int counter = 0;
    bool is_prime;
    int prime_number = 0;
    
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            //cout << i << endl;
            counter++;
            // if the number n is divisible by number i, add one to the counter; keep track of factors of the number
        }
    }
    if (counter > 2 || n <= 1) { // if the number has more than two factors it is not prime
        is_prime = false;
    }
    else {
        is_prime = true;
        prime_number = i;
    }
    return is_prime;
}

// function will output the next prime number
int nextPrime(int g)
{
    int nextNum = 0;
    bool prime_check = false;
    int i;
    double z = g + 50.0;
    
    // i starts at g + 1 because we do not want to include g in the range
    for (i = g + 1; i <= z; i++) {
        bool prime_check = isprime(i); // will call the check function to see if number is prime
        if (prime_check) {
            nextNum = i; // if the number is prime then the next prime is the current value of i
            i = z;       // end the for loop
        }
        
    }
    return nextNum;
}


// main function
int main()
{
    int y;
    cin >> y;
    
    int k = nextPrime(y);
    
    cout << k << endl;
    
    return 0;
}

