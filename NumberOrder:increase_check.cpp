/* Perogram reads series of numbers and state whether they are in increasing order, decreasing order, or neither
 */

#include <iostream>
using namespace std;

int main()
{
    int user_input;
    int counter = 0;
    int first;
    int third;
    int second;
    
    cout << "Enter a series of numbers: ";
    cin >> user_input;
    //cout << "user input: " << user_input << endl << endl;
    first = user_input;
    cin >> user_input;
    second = user_input;
    cin >> user_input;
    third = user_input;
    
    if ((first > second) && (second > third)) {
        cout << "Decreasing order";
    }
    else if ((first < second) && (second < third)){
        cout << "Increasing order" << endl;
    }
    else {
        cout << "Neither" << endl;
    }
    
    
    
    return 0;
}
