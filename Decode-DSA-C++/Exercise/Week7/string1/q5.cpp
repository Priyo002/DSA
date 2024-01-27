#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    getline(cin,s);

    int prod = 1;
    int ans = 0;
    for(int i=s.length()-1;i>=0;i--){
        ans += (s[i]-'0')*prod;
        prod *= 10;
    }
    cout << ans;
    return 0;
}