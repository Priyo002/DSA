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

int n,k;
int dp[2001][2001];

int f(int curr,int len){

    if(len == k) return 1;

    if(dp[curr][len]!=-1) return dp[curr][len];

    int temp = curr;
    int ans = 0;
    while(temp<=n){
        ans += f(temp,len + 1);
        ans %= mod;
        temp += curr;
    }

    return dp[curr][len] = ans;
}

void solve(){
    cin >> n >> k;

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for(int i=1;i<=n;i++){
        ans += f(i,1);
        ans %= mod;
    }

    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();


    return 0;
}