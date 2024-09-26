#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
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
vector<list<pair<int,int>>> graph;
 
void solve(){
    cin >> n >> m;
 
    graph.assign(n+1,list<pair<int,int>>());
   
    vector<int> ans;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({w,v});
    }
    
    vector<int> dist(n+1,0);
 
    dist[1] = 0;
 
    for(int i=0;i<n;i++){
        for(int u=1;u<=n;u++){
            if(dist[u]==INF) continue;
            for(auto &neigh : graph[u]){
                int v = neigh.second, w = neigh.first;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
 
    bool isNegCycle = false;
    vector<int> parent(n+1,-1);
 
    for(int i=0;i<n;i++){
        for(int u=1;u<=n;u++){
            if(dist[u]==INF) continue;
            for(auto &neigh : graph[u]){
                int v = neigh.second, w = neigh.first;
                if(dist[v] > dist[u] + w){
                    parent[v] = u;
                    dist[v] = dist[u] + w;
                    isNegCycle = true;
                }
            }
        }
    }
    if(isNegCycle){

        int x = 0;
        for (int i = 1; i <= n; i++){
            if (parent[i] != -1){
                x = i;
                break;
            }
        }

        vector<int> cycle;
        unordered_set<int> st;
        while (st.find(x) == st.end()){
            cycle.push_back(x);
            st.insert(x);
            x = parent[x];
        }
        cycle.push_back(x);
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        
        unordered_set<int> final;

        for (auto &i : cycle){
            cout << i << " ";
            if (final.find(i) != final.end()){
                break;
            }
            final.insert(i);
        }
    
    }
    else{
        cout << "NO" << endl;
    }
    
}
 
int32_t main(){
    
    init();
    int _t = 1;
   // cin >> _t;
    while(_t--)
        solve();
 
 
    return 0;
}