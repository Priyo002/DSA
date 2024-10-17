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
vector<list<int>> graph;
vector<int> depth,parent,mxDepth;
vector<bool> isLeaf;

void dfs(int src,int par,int dep){
    depth[src] = dep;
    parent[src] = par;
    int cntChild = 0;
    for(auto &neigh : graph[src]){
        if(neigh!=par){
            cntChild++;
            dfs(neigh,src,dep+1);
        }
    }
    if(cntChild==0){
        mxDepth[src] = dep;
        isLeaf[src] = true;
    }
    for(auto &neigh : graph[src]){
        if(neigh!=par){
            mxDepth[src] = max(mxDepth[neigh],mxDepth[src]);
        }
    }
    
}

void solve(){
    
    cin >> n;

    graph.assign(n+1,list<int>());
    depth.assign(n+1,0);
    parent.assign(n+1,0);
    isLeaf.assign(n+1,false);
    mxDepth.assign(n+1,0);

    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,0,0);

    map<int,vector<int>> mp;

    for(int i=1;i<=n;i++){
        mp[depth[i]].push_back(i);
    }

    vector<int> pref(n+2,0);

    for(int i=1;i<=n;i++){
        for(auto &src : mp[i]){
            pref[i]++;
            pref[mxDepth[src]+1]--;
        }
    }

    for(int i=1;i<=n;i++){
        pref[i] += pref[i-1];
    }

    int ans = 1e18;
    for(int i=1;i<=n;i++){
        ans = min(ans,(n-1) - pref[i]);
    }
    if(ans==1e18) ans = 0;
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