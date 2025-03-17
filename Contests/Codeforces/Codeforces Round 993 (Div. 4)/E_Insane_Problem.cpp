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
    int k,l1,r1,l2,r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    int ans = 0;
    int powK = 1;
    for(int i=0;i<31,powK<=1e9;i++){
        ans += max(min(r2/powK,r1) - max((l2 + powK-1)/powK , l1) + 1, 0LL); 
        powK *= k;
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