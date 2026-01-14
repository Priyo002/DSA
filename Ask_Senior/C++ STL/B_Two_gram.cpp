#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e9+7;
const long long INF = 1e18;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<string,int> mp;

    for(int i=0;i<n-1;i++){
        string temp = "";
        temp += s[i];
        temp += s[i+1];
        mp[temp]++;
    }

    int f = 0;
    string ans;
    for(auto &x : mp){
        if(x.second > f){
            ans = x.first;
            f = x.second;
        }
    }
    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}