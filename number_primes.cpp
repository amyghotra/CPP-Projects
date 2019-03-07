/*
 this program asks the user for a range and then print out the number of primes within that range
 */


#include <iostream>
#include <cmath>
using namespace std;

// function to test if number is prime
bool isPrime(int n){
    int i;
    int counter =0;
    bool prime;
    int prime_number = 0;
    
    for (i = 1; i <= n; i++) {
        if (n % i == 0) {
            counter++;
        }
    }
    if (counter > 2 || n <= 1) {
        prime = false;
    }
    else {
        prime = true;
        prime_number = i;
    }
    return prime;
}

// function will count the number of primes number present within a given range
int countPrimes(int a, int b)
{
    int counter = 0;
    int i;
    bool prime_check;
    
    // loop starts at a and ends at b
    for (i = a; i <= b; i++) {
        bool prime_check = isPrime(i);  // program calls above function to check if current i value is prime
        if (prime_check) {              // if the number is prime add +1 to counter
            counter++;                  // cuonter used to keep track of how many primes are in the range
        }
        else {
            cout << endl;
        }
        
    }
    return counter;                     // function will return the value of counter
}


// main function
int main()
{
    int g;
    cin >> g;
    int d;
    cin >> d;
    int num_primes =  countPrimes(g , d);
    
    cout << num_primes;
   
    
    
    return 0;
}


