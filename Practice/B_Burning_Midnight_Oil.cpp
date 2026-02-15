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

bool check(int v, int n, int k){
    int cnt = v, deno = k;
    while((v/deno) > 0){
        cnt += (v/deno);
        if(cnt >= n) return true;
        deno *= k;
    }
    return (cnt>=n);
}

void solve(){
    int n, k;
    cin >> n >> k;

    int lo = 1, hi = LLONG_MAX;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid, n, k)){
            ans = mid;
            hi = mid - 1;
        }
        else{
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