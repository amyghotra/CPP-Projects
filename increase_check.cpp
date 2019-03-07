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
    //int higher;
    //int mid;
    //int lower;
    
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
    
    
    /*
    if (first > second) {
        higher = first;
        lower = second;
        if (third < lower) {
            cout << "Decreasing order";
        }
        else if(third > lower){
            cout << "Neither";
        }
    }
    */
    
    
    
    
    //for (i = 0; i <= 4; i++) {
        /*cin >> user_input;
        if (lower > user_input) {
            higher = lower;
            mid = user_input;
            cin >> user_input;
            if (mid > user_input) {
                cout << "Decreasing" << endl;
            }
            else {
                cout << "Neither" << endl;
            }
        }
        else if (lower < user_input){
            higher = user_input;
            cin >> user_input;
            if (user_input > higher) {
                cout << "Increasing" << endl;
            }
            else {
                cout  << "Neither" << endl;
            }
        }
        else {
            cout << "invalid input?" << endl;
        }*/
    //}
    
    return 0;
}
