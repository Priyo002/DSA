#include<bits/stdc++.h>
using namespace std;

int main(){

    string s,t;
    cout << "Enter first string : ";
    getline(cin,s);
    cout << "Enter second string : ";
    getline(cin,t);

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t) cout << "Yes";
    else cout << "No";

    
    return 0;
}