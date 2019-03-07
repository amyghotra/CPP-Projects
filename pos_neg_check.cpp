/*

  program reads an integer and prints whether is it negative, 0 , or positive
 */

#include <iostream>
using namespace std;

int main()
{
    int user_input;
    char op;
    int sum;
    //bool operat = false;
    
    cout << "Enter an integer: ";
    cin >> user_input;
    
    if (user_input == 0) {
        cout << "Zero" << endl;
    }
    else if(user_input > 0){
        cout << "Positive integer" << endl;
    }
    else {
        cout << "Negative integer" << endl;
    }
    return 0;
}
