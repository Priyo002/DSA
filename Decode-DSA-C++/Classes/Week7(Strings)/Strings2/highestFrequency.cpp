#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "leetcode";
    
    vector<int> v(26,0);
    for(int i=0;i<s.length();i++){
        v[s[i]-'a']++;
    }

    int maxi = 0;
    for(int i=0;i<26;i++){
        maxi = max(maxi,v[i]);
    }
    for(int i=0;i<26;i++){
        if(v[i]==maxi) cout << (char)(i+97) << " " << maxi << endl;
    }


}