/*
 Amy Ghotra
 
 This program asks the user for the width and length of a box and outputs the box
 */

#include <iostream>
using namespace std;

// main function
int main()
{
    // variables
    int width;
    int height;
    int i;
    int j;
    string s = "*";//string askterisk
    
    //ask for inputs
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;
    
    //for loop to run program and output asterisk
    for (i = 0; i < height; i++) {
        cout << endl;
        for (j = 0; j < width; j++) {
            cout << s;
        }
        
    }
    
    return 0;
}
