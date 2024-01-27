#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    getline(cin,s);
    
    vector<string> v;
    stringstream str(s);
    string temp;
    while(str>>temp){
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    // for(int i=0;i<v.size();i++)
    // cout << v[i]<<endl;
    cout << v[v.size()-1];
    return 0;
}