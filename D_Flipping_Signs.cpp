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

int n;
vector<int> arr;
int done[2][100001], dp[2][100001];

int f(int idx, int parity){
    if(idx == n){
        return (parity == 0 ? 0 : -INF);
    }

    if(done[parity][idx]) return dp[parity][idx];

    int ans = arr[idx] + f(idx+1, parity);
    ans = max(ans, -arr[idx] + f(idx + 1, !parity));

    done[parity][idx] = 1;
    return dp[parity][idx] = ans;
}

void solve(){
    cin >> n;
    arr.assign(n, -1);
    for(int &x : arr){
        cin >> x;
    }

    memset(done, 0, sizeof(done));
    memset(dp, -1, sizeof(dp));

    cout << f(0, 0);
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}