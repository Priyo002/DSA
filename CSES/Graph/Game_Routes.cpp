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
vector<list<int>> graph;
vector<int> inDegree;


vector<int> topoSort(){
    queue<int> qu;

    vector<int> topo;
    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            qu.push(i);
        }
    }

    while(qu.size()){
        auto curr = qu.front();
        qu.pop();

        topo.push_back(curr);

        for(auto &neigh : graph[curr]){
            inDegree[neigh]--;
            if(inDegree[neigh]==0){
                qu.push(neigh);
            }
        }
    }
    return topo;
}
void solve(){
    
    cin >> n >> m;

    graph.clear();
    graph.resize(n+1,list<int>());

    inDegree.assign(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        graph[u].push_back(v);
        inDegree[v]++;
    }

    vector<int> topo = topoSort();

    vector<int> dp(n+1,0);
    dp[1] = 1;

    for(auto &src : topo){
        for(auto &neigh : graph[src]){
            dp[neigh] += dp[src];
            dp[neigh] %= mod;
        }
    }

    cout << dp[n] << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
   // cin >> _t;
    while(_t--)
        solve();


    return 0;
}