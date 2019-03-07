/*
 this program aksks for two inputs and outputs whether one divides into the other or not
 */


 #include <iostream>
 #include <cmath>
 using namespace std;
 
bool isDivisibleBy(int a, int e)
{
     bool truth;
     if (e == 0) {
         //cout << "invalid output";
         truth = false;
     }
     else {
        if (a % e == 0) {
            truth = true;
        }
        else {
            truth = false;
        }
     }
     
 return truth;
}

int main()
{
     int n;
     int d;
     cin >> n >> d;
     bool result = isDivisibleBy(n , d);
     
     if (result) {
         cout << "true";
     }
     else if (!result) {
         cout << "flase";
     }
     else {
         cout << " ... ";
     }
    
 
 
 return 0;
    
}
