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
    string s;
    cin >> n >> s;
 
    int mx = 0, my = 0;
    int ans = 1;
    for(char &c : s) {
        int dx = 0, dy = 0;
        if(c == 'L') dx = -1;
        if(c == 'R') dx = 1;
        if(c == 'U') dy = -1;
        if(c == 'D') dy = 1;
        if(dx * mx == -1 || dy * my == -1) {
            mx = 0;
            my = 0;
            ans++;
        }
        if(mx == 0) mx = dx;
        if(my == 0) my = dy;
    }
    cout << ans << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}