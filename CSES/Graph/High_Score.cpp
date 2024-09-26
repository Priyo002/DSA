#include<bits/stdc++.h>
using namespace std;
using pp = pair<int,int>;

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
vector<list<pp>> graph;

void solve(){

    cin >> n >> m;

    graph.clear();
    graph.resize(n+1,list<pp>());

    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;

        graph[u].push_back({c,v});
    }

    vector<int> dist(n+1,-INF);

    dist[1] = 0;

    for(int i=1;i<=n-1;i++){
        for(int u=1;u<=n;u++){
            if(dist[u]==-INF) continue;
            for(auto &neigh : graph[u]){
                int v = neigh.second, w = neigh.first;
                if(dist[u] + w > dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

   
    for(int u=1;u<=n;u++){
        if(dist[u]==-INF) continue;
        for(auto &neigh : graph[u]){
            int v = neigh.second, w = neigh.first;
            if(dist[u] + w > dist[v]){//positive cycle exists
                //BFS (checking if we can reach node 'n' from node 'u' or not)
                queue<int> qu;
                qu.push(u);

                vector<int> visited(n+1,0);
                visited[u] = 1;

                while(qu.size()){
                    auto curr = qu.front();
                    qu.pop();
                    if(curr==n){
                        cout << -1 << endl;
                        return;
                    }
                    for(auto &neigh : graph[curr]){
                        if(!visited[neigh.second]){
                            visited[neigh.second] = 1;
                            qu.push(neigh.second);
                        }
                    }
                }
            }
        }
    }
    

    cout << dist[n];
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}