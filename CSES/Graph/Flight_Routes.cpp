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

int n,m,k;
vector<vector<int>> dist;
vector<vector<pair<int,int>>> graph;

void dijkstra(int src){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    pq.push({0,1}); // {cost, node}
    dist[1][0] = 0;

    while(pq.size()){
        auto [cost, currNode] = pq.top();
        pq.pop();

        if(dist[currNode][k-1] < cost) continue;

        for(auto &[neigh,edgeWt] : graph[currNode]){

            if(dist[neigh][k-1] > cost + edgeWt){
                dist[neigh][k-1] = cost + edgeWt;
                pq.push({dist[neigh][k-1],neigh});
                sort(dist[neigh].begin(),dist[neigh].end());
            }
        }
    }
}

void solve(){
    cin >> n >> m >> k;

    dist.assign(n+1,vector<int>(k,INF));
    graph.assign(n+1,vector<pair<int,int>>());

    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        graph[u].push_back({v,c});
    }

    dijkstra(1);

    for(auto &x : dist[n]){
        cout << x << " ";
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