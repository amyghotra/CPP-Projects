/*
 this program will ask the user for an input and output whether the number is prime or now
 */

 #include <iostream>
 #include <cmath>
 using namespace std;

// function to check if number is prime:
 bool isPrime(int n)
{
    // variables which will be used
     int i;
     int counter =0;
     bool prime;
     
     for (i = 1; i <= n; i++) {
         if (n % i == 0) {
             counter++;
             // if the number n is divisible by number i, add one to the counter
             // created counter in order to keep track of factors of the number
         }
     }
     if (counter > 2 || n <= 1) { // if the number has more than two factors it is not prime
         prime = false;
     }
     else {
         prime = true;
     }
    return prime;
 }
 
 int main()
 {
     int a;
     cin >> a;
     bool primeNum = isPrime(a);
     
     if (primeNum) {
         cout << "true"; // number = prime
     }
     else {
         cout << "false"; // numer != prime
     }
     
     return 0;
 }
