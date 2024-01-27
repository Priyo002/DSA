#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    getline(cin,s);
    int x = stoi(s);
    int y = x;
    int maxi = INT_MIN;
    int r;
    while(x){
        r = x%10;
        maxi = max(maxi,r);
        x/=10;
    }
    int max2 = INT_MIN;
    while(y){
        r = y%10;
        if(r!=maxi) max2 = max(max2,r);
        y/=10;
    }

    cout << max2;
    return 0;
}