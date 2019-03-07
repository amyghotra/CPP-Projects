/*
 This program will:
 Open a file with the name hello.txt.
 Store the message “Hello, World!” in the file.
 Close the file.
 Open the same file again.
 Read the message into a string variable and print it.
 */

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string message;
    // to write to a file: use "ofstream" variable
    ofstream out_file;
    // open the file
    out_file.open("hello.txt");
    // store text into file
    out_file << "Hello, World!" << endl;
    // close file
    out_file.close();
    
    // to read anything from a file stream: use ifstream variable
    // open the stream:
    ifstream in_file;
    in_file.open("hello.txt");
    
    // read the message in the file into the "message" string variable
    getline(in_file, message);
    
    cout << message << endl;
    
    in_file.close();
    
    return 0;
}
