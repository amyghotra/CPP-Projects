/*
 amy ghotra
 vectors 4
 */

// libraries
#include <vector>
#include <iostream>
using namespace std;

// function prototype
vector<int> sumPairWise(vector<int> &vq, vector<int> &v2);

// main function
int main()
{
    // create vector variable which will store final vector (vector returned from vector funtion)
    vector<int> newVect;
    
    // create new vector
    vector<int> v1;
    int first;
    cout << "Enter numbers: ";
    // have users input values into the vector
    while (cin >> first) {
        v1.push_back(first);
    }
    
    // second vector
    int second;
    vector<int> v2;
    cout << "enter numbers ";
    // have users input values into the vector
    while (cin >> second) {
        v2.push_back(second);
    }
    
    // set value of newVevt to the value of the vect received from the vector function
    newVect = sumPairWise(v1, v2);
    
    for (int i = 0; i < newVect.size() ; i++) {
        cout << newVect[i] << " ";
    }
    cout << endl;
    return 0;
}

// vector function
vector<int> sumPairWise(vector<int> &v1, vector<int> &v2)
{
    // variable which will be used to add together contents of the vectors
    int added;
    vector<int> addedVect; // vector to hold the added integers
    int smallerVect; // integer to hold the smaller vector size
    int largerVect; //integer to hold the larger vector size
    int first_size = v1.size(); // get the size of the first vect
    int second_size = v2.size(); // get the size of the second vect
    
    // use conditionals to see which vector is larger
    if (first_size > second_size) {
        smallerVect = second_size;
        largerVect = first_size;
    }
    if (second_size > first_size) {
        smallerVect = first_size;
        largerVect = second_size;
    }
    if (second_size == first_size) {
        smallerVect = first_size;
        largerVect = second_size;
    }
    
    // use for loops to add corresponding values and add the sum to the new vector
    for (int i = 0; i < smallerVect; i++) {
        added = v1[i] + v2[i];
        addedVect.push_back(added);
    }
    
    // if one  vector is larger than the other
    // use another loop to add the values to the new vector which holds the added values;
    if (v1.size() == largerVect) {
        for (int j = smallerVect; j < largerVect; j++) {
            added = v1[j];
            addedVect.push_back(added);
        }
    }
    if (v2.size() == largerVect) {
        for (int j = smallerVect; j < largerVect; j++) {
            added = v2[j];
            addedVect.push_back(added);
        }
    }
    
    return addedVect;
}
