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

int n,m;
vector<vector<int>> Edges;
vector<int> parent,rankk;

int find_parent(int x){
    if(x==parent[x]) return x;
    return parent[x] = find_parent(parent[x]);
}

void addEdge(int u,int v){
    u = find_parent(u);
    v = find_parent(v);
   
    if(rankk[u]>=rankk[v]){
        rankk[u] += rankk[v];
        parent[v] = u;
    }
    else{
        rankk[v] += rankk[u];
        parent[u] = v;
    }
}

void solve(){

    cin >> n >> m;

    Edges.clear();
    parent.resize(n+1);
    rankk.resize(n+1,1);

    for(int i=1;i<=n;i++) parent[i] = i;

    for(int i=0;i<m;i++){
        int u,v,c;
        cin >> u >> v >> c;
        Edges.push_back({c,u,v});
    }

    sort(Edges.begin(),Edges.end());

    int ans = 0;
    for(auto &x : Edges){
        int c = x[0], u = x[1], v = x[2];
        if(find_parent(u)==find_parent(v)) continue;
        addEdge(u,v);
        ans += c;
    }
    int cc = 0;
    for(int i=1;i<=n;i++){
        if(find_parent(i)==i) cc++;
    }
    if(cc>1){
        cout << "IMPOSSIBLE";
    }
    else cout << ans;
    
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}