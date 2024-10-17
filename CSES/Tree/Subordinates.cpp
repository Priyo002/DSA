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

vector<list<int>> graph;
vector<int> subTreeSize;

void dfs(int src,int par){
    subTreeSize[src] = 0;
    for(auto &neigh : graph[src]){
        if(neigh==par) continue;
        dfs(neigh,src);
        subTreeSize[src] += 1+subTreeSize[neigh];
    }
}

void solve(){
    int n;
    cin >> n;

    graph.assign(n+1,list<int>());
    subTreeSize.assign(n+1,0);

    for(int i=2;i<=n;i++){
        int par;
        cin >> par;
        graph[par].push_back(i);
        graph[i].push_back(par);
    }

    dfs(1,0);

    for(int i=1;i<=n;i++){
        cout << subTreeSize[i] << " ";
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