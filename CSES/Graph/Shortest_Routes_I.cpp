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
vector<list<pair<int,int>>> graph;
vector<int> dist,visited;

void dijkstra(int src){

    dist.clear();
    visited.clear();

    dist.resize(n+1,1e18);
    visited.resize(n+1,0);

    priority_queue<pair<int,int>> pq;
    pq.push({-0,src});

    dist[src] = 0;

    while(pq.size()){
        auto curr = pq.top();
        pq.pop();

        int currNode = curr.second;

        if(visited[currNode]) continue;

        visited[currNode] = 1;

        for(auto neigh : graph[currNode]){

            int edgeWt = neigh.second;

            if(dist[neigh.first] > dist[currNode] + edgeWt){
                dist[neigh.first] = dist[currNode] + edgeWt;
                pq.push({-dist[neigh.first],neigh.first});
            }
        }
    }
}

void solve(){
    cin >> n >> m;

    graph.clear();
    graph.resize(n+1,list<pair<int,int>>());

    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;

        graph[u].push_back({v,wt});
    }

    dijkstra(1);

    for(int i=1;i<=n;i++){
        cout << dist[i] << " ";
    }
    cout << endl;
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