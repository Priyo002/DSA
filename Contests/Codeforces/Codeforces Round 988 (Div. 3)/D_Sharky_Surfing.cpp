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
    int n,m,L;
    cin >> n >> m >> L;

    vector<vector<int>> hurdels;

    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        hurdels.push_back({l,r,0});
    }

    for(int i=0;i<m;i++){
        int x,v;
        cin >> x >> v;
        hurdels.push_back({x,v,1});
    }

    sort(hurdels.begin(),hurdels.end());

    int currPower = 1;
    int ans = 0;

    priority_queue<int> pq;

    for(auto &x : hurdels){
        if(x[2]){ // power-up
            pq.push(x[1]);
        }
        else{ // hurdel
            int r = x[1], l = x[0];
            int need = r-l+1;
            if(currPower>need){
                continue;
            }
            else{
                while(pq.size() && currPower<=need){
                    auto curr = pq.top();
                    pq.pop();
                    currPower += curr;
                    ans++;
                }
                if(currPower<=need){
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }
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