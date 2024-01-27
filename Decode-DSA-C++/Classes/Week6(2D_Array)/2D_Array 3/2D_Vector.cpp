#include<bits/stdc++.h>
using namespace std;

int main(){

    //vector<int> v; 1D vector
    vector< vector<int> > v;//2D vector
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    
    v1.push_back(1);
    v1.push_back(2);

    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);


    v.push_back(v1);
    v.push_back(v2);

    cout << v[1][2] << endl;

    cout << v.size() << endl;
    cout << v[0].size();

    return 0;
}