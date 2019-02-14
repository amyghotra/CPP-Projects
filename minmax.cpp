/*
 
 Amy Ghotra
 
 Professor Maryash
 
reads through the file (reads only through the dates specified), and finds the maxiumum and minimum amount of East Storage

 */

#include <iostream> // for cin and cout
#include <fstream> // for ifstream and ofstream
#include <climits> // to use INT_MAX variable
#include <cstdlib> // "cstandard": to use exit function
using namespace std;

//main function
int main()
{
    string date;
    string junk;
    double eastSt, eastEl;
    double westSt, westEl;
    double min_val = 1000;
    double max_val = 0;
    
    ifstream in_file;
    in_file.open("Current_Reservoir_Levels.tsv");
    
    if (in_file.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

        getline(in_file , junk);
        
        while (in_file >> date >> eastSt >> eastEl >> westSt >> westEl) {
            
            in_file.ignore(INT_MAX, '\n');
            
            if (min_val > eastSt) {
                min_val = eastSt;
            }
            if (max_val < eastSt)
            {
                max_val = eastSt;
            }
        }
    cout << "minimum storage in East basin: " << min_val << endl;
    cout << "MAXimum storage in East basin: " << max_val << endl;
    
    return 0;
}
