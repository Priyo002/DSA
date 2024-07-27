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
vector<int> dist,cnt;

void bfs(int src){
    dist.clear();
    dist.resize(n+1,1e18);

    cnt.clear();
    cnt.resize(n+1,0);

    queue<int> qu;
    qu.push(src);

    dist[src] = 0;
    cnt[src] = 1;

    while(qu.size()){
        auto curr = qu.front();
        qu.pop();

        for(auto neigh : graph[curr]){
            if(dist[neigh]==1e18){
                dist[neigh] = 1+dist[curr];
                cnt[neigh] = cnt[curr];
                cnt[neigh] %= mod;
                qu.push(neigh);
            }
            else if(dist[neigh]==1+dist[curr]){
                cnt[neigh] += cnt[curr];
                cnt[neigh] %= mod;
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

    bfs(1);

    cout << (cnt[n]%mod) << endl;
    
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