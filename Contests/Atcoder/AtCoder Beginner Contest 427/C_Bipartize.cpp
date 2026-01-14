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
    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++){
        cin >> edges[i].first >> edges[i].second;
    }

    int ans = 1e9;
    for(int col=0;col<(1LL<<n);col++){
        int cnt = 0;
        for(auto &edge : edges){
            int u = edge.first, v = edge.second;
            if(((col>>u) & 1) == ((col>>v) & 1)) { // same color
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();


    return 0;
}