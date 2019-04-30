/*
 
 Amy Ghotra
 
 
 compares the level of West and East elevation over the user-specified timeline, then prints out the date as well as which side-- west or east-- had the higher elevation
 
 */

#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
using namespace std;

//main function
int main()
{
    //variables
    string input_date1;
    string input_date2;
    string date;
    string junk;
    double eastSt, eastEl;
    double westSt, westEl;
    bool rec = false;
    
    //get user input:
    cout << "Enter starting date: ";
    cin >> input_date1;
    cout << "Enter ending date: ";
    cin >> input_date2;
    
    // open and read file
    ifstream in_file;
    in_file.open("Current_Reservoir_Levels.tsv");
    
    // test for file failure
    if (in_file.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    
    getline(in_file , junk);
    
    while (in_file >> date >> eastSt >> eastEl >> westSt >> westEl) {
        
        if ((date >= input_date1) && (date <= input_date2)){
            if (eastEl > westEl) {
                cout << date << " " << "East" << endl;
            }
            if (westEl > eastEl) {
                cout << date << " " << "West" << endl;
            }
        }
        
        
    
    
    }
    

    return 0;
}
