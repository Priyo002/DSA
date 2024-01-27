#include<bits/stdc++.h> //All header files are added here
using namespace std;

int main(){
    
    vector<int> v(5,7); //Initial size is 5 and each element is 7
    cout << v.size() << endl;
    cout << v[0] << endl;
    //cout << v[0]; //By default each element is 0

    cout << v.at(2) << endl; // Same as v[2]

    //Input
    for(int i=0;i<v.size();i++){
        cin >> v[i];
    }
    cout << endl;

    sort(v.begin(),v.end());

    //Output after sorting
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }

    return 0;
}