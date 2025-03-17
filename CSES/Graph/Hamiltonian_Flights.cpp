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

int n,m;
vector<vector<int>> graph,dp;

int f(int src,int mask){
    if(src == n-1){
        return (mask == (1<<n)-1);
    }

    if(dp[src][mask]!=-1) return dp[src][mask];

    int ans = 0;
    for(auto &neigh : graph[src]){
        if((mask>>neigh)&1) continue;
        ans += f(neigh,(mask|(1<<neigh)));
        ans %= mod;
    }
    
    return dp[src][mask] = ans;
}

void solve(){
    cin >> n >> m;
    
    graph.assign(n,vector<int>());
    dp.assign(n,vector<int>((1<<n)-1,-1));

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
    }

    cout << f(0,1) << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}