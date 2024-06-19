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
vector<int> color;
bool isBipartite;

void dfs(int src,int col){
    color[src] = col;
    for(auto neigh : graph[src]){
        if(color[neigh]==-1){
            dfs(neigh,3-col);
        }
        else{
            if(color[src]==color[neigh]){
                isBipartite = false;
            }
        }
    } 
}

void solve(){

    cin >> n >> m;

    graph.clear();
    graph.resize(n+1,list<int>());

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    isBipartite = true;
    color.resize(n+1,-1);

    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            dfs(i,1);
        }
    }

    if(isBipartite){
        for(int i=1;i<=n;i++){
            cout << color[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
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