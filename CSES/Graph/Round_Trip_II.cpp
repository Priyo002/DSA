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
vector<int> inRecursion,visited,parent;
bool isCycle;


void dfs(int src,int par){
    parent[src] = par;
    inRecursion[src] = 1;
    visited[src] = 1;

    for(auto &neigh : graph[src]){
        if(!visited[neigh]){
            dfs(neigh,src);
        }
        else if(inRecursion[neigh]){
            isCycle = true;
            vector<int> ans;
            int currNode = src;
            ans.push_back(currNode);
            while(currNode!=neigh){
                currNode = parent[currNode];
                ans.push_back(currNode);
            }
            ans.push_back(src);
            cout << ans.size() << endl;
            reverse(ans.begin(),ans.end());
            for(auto &x : ans) cout << x << " ";
            exit(0);
        }
    }
    inRecursion[src] = 0;
}

void solve(){
    cin >> n >> m;

    graph.assign(n+1,vector<int>());
    inRecursion.assign(n+1,0);
    parent.assign(n+1,-1);
    visited.assign(n+1,0);
    isCycle = false;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i] && !isCycle){
            dfs(i,-1);
        }
    }

    cout << "IMPOSSIBLE";

}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}