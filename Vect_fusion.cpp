/*
 amy ghotra
 vectors 3
 */
#include <vector>
#include <iostream>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta);

int main()
{
    //
    //
    //
    //
    
    vector<int> v1;
    v1.push_back(7);
    v1.push_back(13);
    v1.push_back(69);
    v1.push_back(666);
    
    vector<int> v2;
    
    vector<int> v3;
    v3.push_back(7);
    v3.push_back(13);
    v3.push_back(69);
    v3.push_back(666);
    
    vector<int> v4;
    
    vector<int> v11;
    vector<int> v33;
    
    gogeta(v1, v2);
    gogeta(v3, v4);
    gogeta(v11, v2);
    gogeta(v33, v4);
    gogeta(v1, v3);
    gogeta(v2, v4);
    
    return 0;
}

void gogeta(vector<int> &goku, vector<int> &vegeta)
{
    if (vegeta.size() == 0 && goku.size() == 0) {
        goku = vegeta;
        return;
    }
    
    // set the value of the first vector to the value(s) of the second vector
    for (int i = 0; i < vegeta.size(); i++) {
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
    // empty out the second vector
    /*for (int i = 0; i < vegeta.size(); i++) {
        vegeta.pop_back();
    }*/
    
    for (int j = 0; j < goku.size(); j++) {
        cout << goku[j] << " ";
    }
    
}
