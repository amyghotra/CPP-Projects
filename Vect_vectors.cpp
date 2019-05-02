/*
 amy ghotra
 vectors
 */


#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n);

int main()
{
    // get input from user
    cout << "enter number";
    int n;
    cin >> n; // save input in a variable

    // make a new vector variable
    vector<int> mainVect;
    
    // call the vector function with the number the user supplied
    // and set the value of mainVect to that vector
    mainVect = makeVector(n);
    
    // print out the contents of the vector 
    for (int i = 0; i < n; i++) {
        cout << mainVect[i] << " ";
    }
    
    return 0;
}

vector<int> makeVector(int n)
{
    vector<int> vect(n);
    
    for (int i = 0; i < n; i++) {
        vect[i] = i;
    }
    
    return vect;
}
