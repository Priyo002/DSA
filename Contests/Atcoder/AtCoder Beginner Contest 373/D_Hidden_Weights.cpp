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

using pp = pair<int,int>;

int n,m;
vector<list<pp>> graph;
vector<int> visited,value;

void dfs(int src,int val){
    visited[src] = 1;
    value[src] = val;
    for(auto &neigh : graph[src]){
        if(!visited[neigh.first]){
            dfs(neigh.first,val+neigh.second);
        }
    }
}

void solve(){
    cin >> n >> m;

    graph.assign(n+1,list<pp>());
    visited.assign(n+1,0);
    value.assign(n+1,0);

    vector<int> edgesCost;
    vector<pp> edge;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge.push_back({u,v});
        edgesCost.push_back(w);
        graph[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++){
        if(!visited[i] && graph[i].size()){
            //cout << i << " ";
            dfs(i,0);
        }
    }
    // vector<int> temp;
    // for(auto &x : edge){
    //     temp.push_back(value[x.second]-value[x.first]);
    //     cout << x.first << " " << x.second << " ";
    //     cout << temp.back() << "\n";
    // }
    // cout << endl;
    for(int i=1;i<=n;i++){
        cout << -value[i] << " ";
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