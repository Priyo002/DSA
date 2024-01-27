#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    getline(cin,s);
    
    int len = s.length();
    cout << len << endl;
    reverse(s.begin(),s.begin() + len/2);
    cout << s;

}