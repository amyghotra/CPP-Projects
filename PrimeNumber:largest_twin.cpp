/*
 program asks the user for a range and outputs the largest twin prime within the given range
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


// function finds the largest twin prime in a given range
int largestTwinPrime(int a, int b)
{
    int largest;
    int j = 0;
    int counter = 0;
    int twins[100];
    bool is_i = false;
    
    // because the array only allows for the storing of 100 units, this conditional was created
    // this gets the largest value faster because th elargest value is the first value it gets
    if ((b-a) > 100) {
        for (int i = b; i >= a; i--) {         // i starts at b and ends at a, decreasing by -1 after each loop
            is_i = isTwinPrime(i);             // checks to see if the current i value is a twin prime
            if (is_i) {                        // if the cuurent value of i is a twin prime
                twins[j] = i;                  // add the value to the array
                j++;                           // increment the value of j by 1
                counter ++;                    // increment the value of counter by 1; keeps track of how many twin primes there are
                i = a;                         // end the loop by setting i equal to a (the last number)
            }
            
        }
        largest = twins[j-1];                  // this sets largest equal to the value in the array
    }
    // if the range is not very big this loop will run:
    else {
        for (int i = a; i <= b; i++) {
            is_i = isTwinPrime(i);          // checks if current i is a twin prime
            if (is_i) {
                twins[j] = i;              // if current i is a twin prime, add it to an array
                j++;                       // increase j by 1
                counter++;                 // increase counter by 1; keeps track of how many twin primes there are
            }
            largest = twins[j -1];         // this sets largest equal to the value in the array
        }
        
    }
 
        if (counter == 0) {             // if no twin primes were found in the given range
        largest = -1;                   // largest is equal to -1
    }
    
    return largest;                     // return the vlaue of largest
}




// main function
int main()
{
    int y;
    int z;
    cin >> y ;
    cin >> z;
    
    int largest = largestTwinPrime(y, z);
    
    cout << largest << endl;
    
    
    return 0;
}

