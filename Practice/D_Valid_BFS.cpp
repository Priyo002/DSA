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

int n;
vector<vector<int>> graph;
vector<int> visited;

vector<int> bfs(){
    queue<int> qu;
    visited.assign(n+1, 0);
    visited[1] = true;
    qu.push(1);

    vector<int> temp;

    while(qu.size()){
        int curr = qu.front();
        qu.pop();
        temp.push_back(curr);
        for(int &neigh : graph[curr]){
            if(!visited[neigh]){
                visited[neigh] = 1;
                qu.push(neigh);
            }
        }
    }

    return temp;
}

void solve(){
    cin >> n;

    graph.assign(n+1, vector<int>());

    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> arr(n), order(n+1); 
    for(int i=0;i<n;i++){
        cin >> arr[i];
        order[arr[i]] = i;
    }

    for(int i=1;i<=n;i++){
        sort(graph[i].begin(), graph[i].end(), [&order](int a, int b){
            return order[a] < order[b];
        });
    }

    vector<int> temp = bfs();
    if(temp == arr) cout << "Yes";
    else cout << "No";
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}