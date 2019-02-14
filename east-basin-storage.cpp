/*
 
Amy Ghotra
 
Professor Maryash
 
asks the user to input string representing the date, and then prints out the East basin storage from that day
 
 */

#include <iostream> // for cin and cout
#include <fstream> // for ifstream and ofstream
#include <climits> // to use INT_MAX variable
#include <cstdlib> // "cstandard": to use exit function
using namespace std;

int main()
{
    // vars
    string date;
    string input_date;
    string junk;
    string eastSt;
    string eastEl;
    string westSt;
    string westEl;
    // get input from user:
    cout << "Enter date: ";
    cin >> input_date;
    //open file; read input file
    ifstream in_file;
    in_file.open("Current_Reservoir_Levels.tsv");
    
    //cerr = error messgage to error stream-- not always visible to user
    if (in_file.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    else
    {
        
        // skip the first line
        getline(in_file , junk);
        // this loop will go through all five coulumns for all rows until end of data:
        while (in_file >> date >> eastSt >> eastEl >> westSt >> westEl) {
        //after we read the first five columns, ignore the rest of the columns:
        in_file.ignore(INT_MAX, '\n');
        //date = input_date;
        if (date == input_date) {
            cout << "East basin storage :" << date << eastSt << endl;
        }
        else
        {
            cout << "error" << endl;
        }
            
        //cout << date << " " << eastSt << endl;
        }

    
    }
    
    in_file.close();
    
    return 0;
}
