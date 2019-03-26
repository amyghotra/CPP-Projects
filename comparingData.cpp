// PART 3 / 3

#include <fstream> // library needed in order to read / edit text files
#include <iostream>
#include <string>
using namespace std;

// function prototypes:

int hamming(string first, string second);

string updatedString(string oldVersion);

int dictionary_read(ifstream &dict, string first_mRNA, string second_mRNA);

string firstmRNA_read(ifstream &dict, string first_read);

string secondmRNA_read(ifstream &dict, string second_string);

int compareHyphenated(string first, string second);

// main function
int main()
{
    //  variables which will be used
    string firstone;
    string first_converted;
    string mRNA_first;
    string second_converted;
    string secondone;
    string mRNA_second;
    int numDifferences;
    int mRNA_differences;
    
    // open up text file with DNA strands
    ifstream fin("mutations.txt");
    if (fin.fail()) {
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }
    // create another variable which will be used to read the contents of the mutations text file
    string strand;
    string randomArray[15];
    
    // store the DNA strands into an array
    for (int i = 0; getline(fin, strand) && i < 15; i++) {
        randomArray[i] = strand;
    }
    
    // read in the "dictionary" text file
    ifstream fin2("codons.tsv");
    if (fin2.fail()) {
        cerr << "File cannot be read, opened, or does not exist.\n";
        exit(1);
    }
    
    for (int k = 0; k < 12; k = k + 2) {
        firstone = randomArray[k];                                  // get the even numbered strings
        mRNA_first = updatedString(firstone);                       // get the mRNA version of the even numbered string
        secondone = randomArray[k + 1];                             // get the odd numbered strings
        mRNA_second = updatedString(secondone);                     // get the mRNA version of the odd numbered string
        numDifferences = hamming(firstone, secondone);              // call function to get number of differences btwn DNA strands
        
        first_converted = firstmRNA_read(fin2, mRNA_first);         // convert the even numbered mRNA strand into an amino acid chain
        second_converted = secondmRNA_read(fin2, mRNA_second);      // convert the odd numbered mRNA strand into an amino acid chain
        
        mRNA_differences = compareHyphenated(first_converted, second_converted); // call function to determine if there's a difference in amino acid chains
        
        // NOTE: even if there is a difference in DNA strands, there does not always have to be a difference in the amino acid chain
        if (numDifferences == 0 && mRNA_differences == 0) {         // if the DNA chains are the same and there is no difference btwn the amino acid chain
            cout << "0 no" << endl;                                 // print "0" to let the user know that there was no difference, and " no" to denote no change in amino structure
            return 0;                                               // end the program
        }
        else if (numDifferences > 0 && mRNA_differences == 0) {     // if there is a difference in dna strands but not amino acid chains
            cout << numDifferences << " no" << endl;                 // print out the number of differences in the DNA chain and state "no" to denote no change in chain structure
            return 0;                                               // end the program
        }
        else if (numDifferences > 0 && mRNA_differences > 0) {      // if there is a difference in dna strands and a difference in the amino acid chain
            cout << numDifferences << " yes" << endl;               // print out # of differences in DNA strand and print out "yes" to denote change in structure
            return 0;
        }
    }
    
    // close the files
    fin.close();
    fin2.close();
    
    return 0;
}


// this function will calculate the number of differences between the two DNA strands
int hamming(string first, string second)
{
    int numDifferences = 0;
    
    for (int i = 0; i < first.length(); i++) {
        if (first[i] != second[i]) {                // if there is a difference in the strands
            numDifferences++;                       // increment the variable by 1
        }
    }

    return numDifferences;                          // returns the number of differences in the strands
}


// this function takes the DNA string and returns the mRNA version
string updatedString(string mRNAversion)
{
    // loop replaces each character as the string is being read
    for (int j = 0; j <= mRNAversion.length(); j++)
    {
        if (mRNAversion[j] == 'A' || mRNAversion[j] == 'a') {
            mRNAversion[j] = 'U';
        }
        else if (mRNAversion[j] == 'T' || mRNAversion[j] == 't') {
            mRNAversion[j] = 'A';
        }
        else if (mRNAversion[j] == 'C' || mRNAversion[j] == 'c') {
            mRNAversion[j] = 'G';
        }
        else if (mRNAversion[j] == 'G' || mRNAversion[j] == 'g') {
            mRNAversion[j] = 'C';
        }
    }
    
    return mRNAversion;                          // returns the updated mRNA version of the DNA string
}

// function will take in the dictionaty and the first (even numbered) mRNA string and return the amino acid chain
string firstmRNA_read(ifstream &dict, string mRNAstring)
{
    bool start = false;
    string hyphenated = "";
    // this prints out the mRNA string:
    for (int q = 0; q < mRNAstring.length(); q = q + 3) {
        
        string newStr = mRNAstring.substr(q, 3);
        
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
    
    return hyphenated;
}

// function will take in the dictionaty and the second (odd numbered) mRNA string and return the amino acid chain
string secondmRNA_read(ifstream &dict, string mRNAstring)
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
    
    return hyphenated;              // returns the amino acid chain
}

// function will compare the two amino acid chains and determine if there was a change in structure
int compareHyphenated(string first, string second)
{
    int counter = 0;
    string one;
    string two;
    
    int len1 = first.length();
    int len2 = second.length();
    
    // if the length of the two chains is different, then there is a clear change in structure
    if (len1 != len2) {
        counter = 1;
        return counter;
    }

    // if length of both is the same, compare the substrings
    for (int i = 0; i < first.length(); i = i + 4) { // increment by 4 in order to account for the hypehns btwn codons
        one = first.substr(i, 3);
        two = second.substr(i, 3);
        
        // if there is a disparity in the subsrtings
        if (one != two) {
            counter++; // increment the counter
            return counter; // return whatever the counter is
        }
    }
    
    return counter;
}
