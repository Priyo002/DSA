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

//BG, BR, BY, GR, GY, or RY = {n+1,n+2,n+3,n+4,n+5}

vector<list<pair<int,int>>> graph;
map<string,int> mp;
map<int,vector<int>> D;
int n,q;

void dijkstra(int src){

    vector<int> dist(n+100,1e18);

    priority_queue<pair<int,int>> pq;

    vector<int> visited(n+100,0);
    pq.push({0,src});
    dist[src] = 0;

    while(pq.size()){
        auto curr = pq.top();
        pq.pop();

        int currNode = curr.second, cost = -curr.first;

        if(visited[currNode]) continue;
        visited[currNode] = 1;

        for(auto &neigh : graph[currNode]){
            if(dist[neigh.first] > neigh.second + cost){
                dist[neigh.first] = neigh.second + cost;
                pq.push({-dist[neigh.first],neigh.first});
            }
        }
    }

    D[src] = dist;
}



void solve(){
    
    cin >> n >> q;

    graph.clear();
    graph.resize(n+100,list<pair<int,int>>());

    mp.clear();

    mp["BG"] = n+1;
    mp["BR"] = n+2;
    mp["BY"] = n+3;
    mp["GR"] = n+4;
    mp["GY"] = n+5;
    mp["RY"] = n+6;

    map<char,vector<int>> mpp;

    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];

        graph[mp[arr[i]]].push_back({i,0});

        char ch1 = arr[i][0], ch2 = arr[i][1];
        mpp[ch1].push_back(i);
        mpp[ch2].push_back(i);
    }

    for(auto &x : mpp){
        vector<int> temp = x.second;
        int k = temp.size();
        for(int i=0;i<k-1;i++){
            int u = temp[i], v = temp[i+1];
            graph[u].push_back({v,v-u});
            graph[v].push_back({u,v-u});
        }
    }

    D.clear();

    for(auto &x : mp){
        dijkstra(x.second);
    }

    while(q--){
        int u,v;
        cin >> u >> v;

        u--,v--;

        vector<int> temp = D[mp[arr[u]]];
        vector<int> t2 = D[mp[arr[v]]];
        int d = t2[u];
        int ans = max(d,temp[v]);
        if(arr[u]==arr[v]) ans = abs(v-u);
        if(ans==1e18) cout << -1;
        else cout << ans;
        cout << endl;
    }

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}