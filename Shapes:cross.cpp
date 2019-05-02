/*
 Amy Ghotra
*/

#include <iostream>
using namespace std;

int main()
{
    // vars
    int row; // rows == the height
    int col; // cols == width
    int height;
    int width;
    
    // inputs from user
    cout << "Input height: ";
    cin >> height;
    // set the width and height to the same value
    width = height;
    
    // loops to draw the figure
    for (row = 1; row <= height; row++) {
        cout << endl;
        for (col = 1; col <= width; col++) {
            // this is what creates the cross:
            //an asterisk will be placed where the row and column are the same value
            // " (col == width - (row -1) " is what draws the diagonal starting from the opposite side
            if ((col == row) || (col == width - (row -1))) {
                cout << "*";
            }
            // this will put emptpy whereever the row != col:
            // this is also what ensures that the asterisks make the shape
            else{
                cout << " "; // comments spaces whereever the rows != cols ; this is what essentially creates the diagonal line
            }
        }
    }
    
    
    return 0;
}
