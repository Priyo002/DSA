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
vector<vector<int>> graph;
vector<int> dp,maxChild;

int dfs(int src){
    if(src == n) return 1;

    if(dp[src]!=-1) return dp[src];

    dp[src] = -INF;
    for(auto &neigh : graph[src]){
        int newDist = 1 + dfs(neigh);
        if(newDist > dp[src]){
            dp[src] = newDist;
            maxChild[src] = neigh;
        }
    }

    return dp[src];
}


void solve(){

    cin >> n >> m;

    graph.assign(n+1,vector<int>());

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    dp.assign(n+1,-1);
    maxChild.resize(n+1);

    int ans = dfs(1);

    if(ans>=0){
        cout << ans << endl;
        int curr = 1;
        while(curr!=n){
            cout << curr << " ";
            curr = maxChild[curr];
        }
        cout << curr << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}