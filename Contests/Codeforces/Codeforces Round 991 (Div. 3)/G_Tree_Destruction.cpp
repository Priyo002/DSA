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

void solve(){
    int n;
    cin >> n;

    vector<int> degree(n+1,0);
    vector<vector<int>> graph(n+1,vector<int>());

    for(int i=1;i<=n-1;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    multiset<pair<int,int>> mt;
    for(int i=1;i<=n;i++){
        mt.insert({degree[i],i});
    }

    int ans = 0;
    int flag = 0;

    while(mt.size()){
        auto curr = *mt.rbegin();
        mt.erase(mt.find(curr));

        if(curr.first <= 1) break;

        ans += curr.first - flag;
        flag = 1;
        for(auto &v : graph[curr.second]){
            if(mt.find({degree[v],v})!=mt.end()){
                mt.erase(mt.find({degree[v],v}));
                degree[v]--;
                mt.insert({degree[v],v});
            }
        }
    }
    if(ans == 0) ans++;
    cout << ans << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}