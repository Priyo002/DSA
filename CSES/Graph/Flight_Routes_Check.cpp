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
vector<int> visited,tout;
vector<list<int>> graph,rgraph;

void dfs1(int src){
    visited[src] = 1;
    for(auto &neigh : graph[src]){
        if(!visited[neigh]){
            dfs1(neigh);
        }
    }
    tout.push_back(src);
}

void dfs2(int src){
    visited[src] = 1;
    for(auto &neigh : rgraph[src]){
        if(!visited[neigh]){
            dfs2(neigh);
        }
    }
}

void solve(){
    cin >> n >> m;

    visited.assign(n+1,0);
    graph.assign(n+1,list<int>());
    rgraph.assign(n+1,list<int>());

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }

    tout.clear();

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }

    reverse(tout.begin(),tout.end());
    visited.assign(n+1,0);

    vector<int> ans;
    for(auto &i : tout){
        if(!visited[i]){
            dfs2(i);
            ans.push_back(i);
        }
    }

    if(ans.size()<=1){
        cout << "YES";
    }
    else{
        cout << "NO" << endl;
        cout << ans[1] << " " << ans[0];
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