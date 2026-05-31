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

vector<int> visited;
vector<vector<int>> graph;

void dfs(int src){
    visited[src] = 1;
    for(int &neigh : graph[src]){
        if(!visited[neigh]){
            dfs(neigh);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    visited.assign(n+1, 0);
    graph.assign(n+1, vector<int>());

    for(int i=0;i<m;i++){
        int u, v, z;
        cin >> u >> v >> z;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cc = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cc++;
        }
    }

    cout << cc;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}