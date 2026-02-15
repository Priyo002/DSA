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

bool check(int val, int n, int m, int k){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt += min(m, (val/i));
        if(cnt>=k) return true;
    }
    return (cnt>=k);
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    int lo = 1, hi = n*m;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid, n, m, k)){
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
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