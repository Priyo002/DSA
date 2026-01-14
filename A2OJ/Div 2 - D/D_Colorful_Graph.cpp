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
    int n, m;
    cin >> n >> m;

    vector<int> color(n);
    map<int,set<int>> mp;
    for(int &x : color){
        cin >> x;
        mp[x].insert(x);
    }

    

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--, v--;

        if(color[u] != color[v]){
            mp[color[u]].insert(color[v]);
            mp[color[v]].insert(color[u]);
        }
    }

    int ans = 0;
    int col = -1;
    for(auto &x : color){
        if(mp[x].size() > ans){
            ans = mp[x].size();
            col = x;
        }
        else if(mp[x].size() == ans){
            col = min(col, x);
        }
    }

    cout << col;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();


    return 0;
}