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

int n,m, total;
vector<vector<int>> graph, rgraph, condensedGraph, condensedRGraph;
vector<int> value, visited, tout, sccNum, totalValue;

void dfs1(int src){
    visited[src] = 1;
    for(auto &neigh : graph[src]){
        if(!visited[neigh]){
            dfs1(neigh);
        }
    }
    tout.push_back(src);
}

void dfs2(int src,int currScc){
    visited[src] = 1;
    sccNum[src] = currScc;
    total += value[src];
    for(auto &neigh : rgraph[src]){
        if(!visited[neigh]){
            dfs2(neigh,currScc);
        }
    }
}


void solve(){
    cin >> n >> m;

    graph.assign(n+1,vector<int>());
    rgraph.assign(n+1,vector<int>());
    value.assign(n+1,0);

    for(int i=1;i<=n;i++){
        cin >> value[i];
    }

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }

    visited.assign(n+1,0);
    
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }

    visited.assign(n+1,0);
    sccNum.assign(n+1,0);

    reverse(tout.begin(),tout.end());

    totalValue.push_back(0);

    int scc = 0;
    for(auto &x : tout){
        if(!visited[x]){
            scc++;
            total = 0;
            dfs2(x,scc);
            totalValue.push_back(total);
        }
    }

    condensedGraph.assign(scc+1,vector<int>());
    condensedRGraph.assign(scc+1,vector<int>());
    vector<int> inDegree(scc+1,0);

    for(int u=1;u<=n;u++){
        for(auto &v : graph[u]){
            if(sccNum[u]!=sccNum[v]){
                condensedGraph[sccNum[u]].push_back(sccNum[v]);
                condensedRGraph[sccNum[v]].push_back(sccNum[u]);
                inDegree[sccNum[v]]++;
            }
        }
    }

    queue<int> qu;
    for(int i=1;i<=scc;i++){
        if(inDegree[i] == 0){
            qu.push(i);
        }
    }

    vector<int> topo;
    while(qu.size()){
        int curr = qu.front();
        qu.pop();

        topo.push_back(curr);
        for(auto &neigh : condensedGraph[curr]){
            inDegree[neigh]--;
            if(inDegree[neigh] == 0){
                qu.push(neigh);
            }
        }
    }

    vector<int> dp(scc+1,0);
    int ans = 0;
    for(auto &v : topo){
        for(auto &x : condensedRGraph[v]){
            dp[v] = max(dp[v],dp[x]);
        }
        dp[v] += totalValue[v];
        ans = max(ans,dp[v]);
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