// PART 1 / 3

//libraries to be used
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// funtion to output the translated characters
char DNA_to_mRNA(char s)
{
    cout << s;
    
    return s;
}

// function to read in the characters of the original string and turn the characters into their corresponding mRNA characters
char DNAbase_to_mRNAbase(char j)
{
    char newChar;                               // create var to store the new character/ corresponding mRNA character, so that it can be used to call the void function, where it will be stored
    
    // conditionals to test what the character is and get the corresponding mRNA character
    if (j == 'A' || j == 'a') {
        newChar = 'U';
        DNA_to_mRNA(newChar);                   // invoke the void function with the new char
    }
    else if (j == 'T' || j == 't') {
        newChar = 'A';
        DNA_to_mRNA(newChar);
    }
    else if (j == 'C' || j == 'c') {
        newChar = 'G';
        DNA_to_mRNA(newChar);
    }
    else if (j == 'G' || j == 'g') {
        newChar = 'C';
        DNA_to_mRNA(newChar);
    }
    
    
    return newChar;
}

// main function which retreives the information from the data.txt file
int main()
{
    ifstream fin("dna.txt");
    if (fin.fail()) {
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }
    string strand;
    while(getline(fin, strand)) {
        cout << endl;   // goes onto new line after a strand is finished being read /  edited
        for (int m = 0; m <= strand.length(); m++) {
            DNAbase_to_mRNAbase(strand[m]);
            
        }
    }
    fin.close();

    return 0;
}
