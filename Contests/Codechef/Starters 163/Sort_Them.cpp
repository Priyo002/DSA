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

int n;
string s,p;
map<char,char> mp;
vector<vector<int>> dp;

int f(int i,int prevSwapped){
    if(i == n){
        return 0;
    }
    if(dp[prevSwapped][i]!=-1) return dp[prevSwapped][i];

    int ans = INF;

    if(i==0){
        ans = min(ans, f(i+1,0));
        ans = min(ans, 1 + f(i+1,1));
    }
    else{
        char prevCh = s[i-1];
        if(prevSwapped) prevCh = mp[s[i-1]];

        if(prevCh<=s[i]){
            ans = min(ans, f(i+1,0));
        }
        if(prevCh<=mp[s[i]]){
            ans = min(ans, 1 + f(i+1,1));
        }
    }
    return dp[prevSwapped][i] = ans;
}

void solve(){

    cin >> n;

    cin >> s >> p;

    vector<int> pos(26,-1);
    for(int i=0;i<26;i++){
        pos[p[i]-'a'] = i+1;
    }

    mp.clear();
    for(int i=0;i<n;i++){
        int idx = 27 - pos[s[i]-'a'] - 1;
        mp[s[i]] = p[idx];
    }

    dp.assign(2,vector<int>(n,-1));

    int ans = f(0,0);
    if(ans == INF) ans = -1;

    cout << ans << endl;
    
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}