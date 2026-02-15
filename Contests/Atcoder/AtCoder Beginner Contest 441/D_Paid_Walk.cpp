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
    int n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;

    vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>>());

    for(int i=0;i<m;i++){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }

    queue<pair<int, pair<int,int>>> qu; // {steps, cost}
    qu.push({0, {1, 0}});

    set<int> st;

    while(qu.size()){
        auto curr = qu.front();
        qu.pop();

        if(curr.first == l) {
            if(curr.second.second >= s && curr.second.second <= t){
                st.insert(curr.second.first);
            }
            continue;
        }

        for(auto &neigh : graph[curr.second.first]){
            qu.push({curr.first+1, {neigh.first, curr.second.second + neigh.second}});
        }
    }

    for(auto &x : st){
        cout << x << " ";
    }
    cout << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}