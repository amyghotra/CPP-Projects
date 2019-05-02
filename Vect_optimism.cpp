/*
 amy ghotra
 vectors 2
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(vector<int> v);

int main()
{
    //vector<int> v={1, 2, -1, 3, 4, -1, 6};
    
    vector<int> v;
    
    /*vector<int> v(7);
    
    v[0] = 1;
    v[1] = 2;
    v[2] = -1;
    v[3] = 3;
    v[4] = 4;
    v[5] = -1;
    v[6] = 6;*/
    
    int input;
    while (cin >> input) {
        v.push_back(input);
    }
    
    
    vector<int> mainVect = goodVibes(v);
    
    for (int i = 0; i < mainVect.size(); i++) {
        cout << mainVect[i] << " ";
    }
    
    return 0;
}

vector<int> goodVibes(vector<int> v)
{
    int pos;
    vector<int> positiveVect;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 0)
        {
            pos = v[i];
            positiveVect.push_back(pos);
        }
    }
    return positiveVect;
}
