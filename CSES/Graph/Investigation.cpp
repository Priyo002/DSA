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

using pp = pair<int,int>;

int n,m;
vector<list<pp>> graph;
vector<int> dist,visited,cnt,minF,maxF;

void dijkstra(int src){
    dist.clear(),visited.clear(),cnt.clear(),minF.clear(),maxF.clear();

    dist.resize(n+1,INF);
    visited.resize(n+1,0);
    cnt.resize(n+1,0);
    minF.resize(n+1,0);
    maxF.resize(n+1,0);

    priority_queue<pp> pq;
    pq.push({0,src});

    dist[src] = 0;
    cnt[src] = 1;
    
    while(pq.size()){
        auto curr = pq.top();
        pq.pop();

        int u = curr.second, cost = -curr.first;

        if(visited[u]) continue;
        visited[u] = 1;
        
        for(auto &neigh : graph[u]){
            int v = neigh.first , w = neigh.second;
            if(dist[v] > cost + w){
                dist[v] = cost + w;
                cnt[v] = cnt[u];
                minF[v] = minF[u]+1;
                maxF[v] = maxF[u]+1;
                pq.push({-dist[v],v});
            }
            else if(dist[v] == cost + w){
                cnt[v] += cnt[u];
                cnt[v] %= mod;
                minF[v] = min({minF[v],minF[u]+1,maxF[u]+1});
                maxF[v] = max({maxF[v],minF[u]+1,maxF[u]+1});
            }
        }
    }
}

void solve(){
	cin >> n >> m;

    graph.clear();
    graph.resize(n+1,list<pp>());

    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        graph[u].push_back({v,c});
    }

    dijkstra(1);

    if(dist[n]==INF) cout << -1;
    else cout << dist[n] << " " << cnt[n] << " " << minF[n] << " " << maxF[n];
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