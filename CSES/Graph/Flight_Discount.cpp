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

using pp = pair<int,int>;

int n,m;
vector<list<pp>> graph,rgraph;

vector<int> dijkstra(int src,bool flag){

    vector<int> dist(n+1,1e18), visited(n+1,0);
    dist[src] = 0;

    priority_queue<pp> pq;
    pq.push({-dist[src],src});

    while(pq.size()){
        auto curr = pq.top();
        pq.pop();

        if(visited[curr.second]==1) continue;

        visited[curr.second] = 1;

        if(flag){
            for(auto neigh : graph[curr.second]){
                int edgeWeight = neigh.second;
                if(dist[neigh.first] > dist[curr.second]+edgeWeight){
                    dist[neigh.first] = dist[curr.second]+edgeWeight;
                    pq.push({-dist[neigh.first],neigh.first});
                }
            }
        }
        else{
            for(auto neigh : rgraph[curr.second]){
                int edgeWeight = neigh.second;
                if(dist[neigh.first] > dist[curr.second]+edgeWeight){
                    dist[neigh.first] = dist[curr.second]+edgeWeight;
                    pq.push({-dist[neigh.first],neigh.first});
                }
            }
        }
    }

    return dist;
}  

void solve(){

    cin >> n >> m;

    graph.clear();
    rgraph.clear();

    graph.resize(n+1,list<pp>());
    rgraph.resize(n+1,list<pp>());

    vector<vector<int>> edge(m,vector<int>(3));

    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        graph[u].push_back({v,c});
        rgraph[v].push_back({u,c});

        edge[i][0] = u, edge[i][1] = v, edge[i][2] = c;
    }

    vector<int> dist1 = dijkstra(1,true), dist2 = dijkstra(n,false);

    int ans = 1e18;
    for(int i=0;i<m;i++){
        int u = edge[i][0], v = edge[i][1], c = edge[i][2];
        ans = min(ans,dist1[u] + (c/2) + dist2[v]);
    }
    
    cout << ans << endl;
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