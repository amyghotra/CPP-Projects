// PART 2 / 3

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// void function to translate the mRNA strand into an amino acid chain, and pring the chain out
void dictionary_read(ifstream &dict, string mRNAstring)
{
    bool start = false;
    string hyphenated = "";
    // this prints out the mRNA string:
    for (int q = 0; q < mRNAstring.length(); q = q + 3) {
        // create a new substring which will be used matched with dictionary keys
        string newStr = mRNAstring.substr(q, 3);
        
        // variables for reading in the dictionary:
        string key, value;
        dict.clear(); // reset error state
        dict.seekg(0); // return file pointer to the beginning
        // this prints out the contents of the tsv file:
        while (dict >> key >> value) {
            if (newStr == key)
            {
                // always starts with "Met"
                if (value == "Met") {
                    start = true;
                }
                if (value == "Stop") {
                    start = false;
                }

                // as long as the program does not detect a "Stop"
                if (start == true) {
                    hyphenated = hyphenated + value + "-";
                }
            }
        }
    }
    if (hyphenated[hyphenated.length() - 1] == '-')
    {
        hyphenated = hyphenated.substr(0,hyphenated.length() - 1);
    }
    cout << hyphenated;
}


// this function translates DNA strands into mRNA strands
string updatedString(string mRNA)
{
    for (int j = 0; j <= mRNA.length(); j++)
    {
        if (mRNA[j] == 'A' || mRNA[j] == 'a') {
            mRNA[j] = 'U';
            //DNA_to_mRNA(newChar);
        }
        else if (mRNA[j] == 'T' || mRNA[j] == 't') {
            mRNA[j] = 'A';
            //DNA_to_mRNA(newChar);
        }
        else if (mRNA[j] == 'C' || mRNA[j] == 'c') {
            mRNA[j] = 'G';
            //DNA_to_mRNA(newChar);
        }
        else if (mRNA[j] == 'G' || mRNA[j] == 'g') {
            mRNA[j] = 'C';
            //DNA_to_mRNA(newChar);
        }
    }
    
    return mRNA; // returns the updated mRNA version of the DNA string
}

// main function
int main()
{
    char updated;
    string newString;
    
    // open up and read the text file
    ifstream fin("dna2b.txt");
    if (fin.fail()) {
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }
    string strand;
    while(getline(fin, strand)) {
        
        newString = updatedString(strand); // send string to another function to get the mRNA version
        
    }
    
    // open up and read the "dictionary" text file
    ifstream fin2("codons.tsv");
    if (fin2.fail()) {
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }
    else {
        dictionary_read(fin2, newString); // take the dictionary and mRNA strand and use them to invoke another function that translates mRNA into amino acid chain
        
    }
    
    fin.close();
    fin2.close();
    
    return 0;
}
