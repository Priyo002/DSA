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
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

int n,m;
vector<list<int>> graph;
vector<int> parent,visited,ans;
bool isCycle;

void dfs(int src,int par){

    parent[src] = par;
    visited[src] = 2;

    for(auto neigh : graph[src]){
        if(neigh==par) continue;
        
        if(visited[neigh]==1){
            dfs(neigh,src);
        }
        else if(visited[neigh]==2 && isCycle==false){
            isCycle = true;
            int curr = src;
            ans.push_back(neigh);
            while(curr!=neigh){
                ans.push_back(curr);
                curr = parent[curr];
            }
            ans.push_back(neigh);
        }
    }
    visited[src] = 3;
}

void solve(){

    cin >> n >> m;

    graph.clear();
    graph.resize(n+1,list<int>());

    int src = -1;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        src = u;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    parent.clear();
    parent.resize(n+1,0);

    visited.clear();
    visited.resize(n+1,1);

    isCycle = false;
    ans.clear();

    for(int i=1;i<=n;i++){
        if(visited[i]==1) dfs(i,0);
    }
    
    if(isCycle){
        cout << ans.size() << endl;
        for(auto x : ans) cout << x << " ";
    }
    else{
        cout << "IMPOSSIBLE";
    }
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}