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
    int x,y,k;
    cin >> x >> y >> k;

    if(x==0 && y==0){
        cout << 0 << endl;
        return;
    }

    int xMove = (x/k) + (x%k!=0);
    int yMove = (y/k) + (y%k!=0);
    
    int mid = max(0LL,xMove-1);
    yMove -= mid;
    yMove = max(0LL,yMove);

    int ans = xMove + mid + yMove + max(0LL,yMove-1);
    if(xMove==0) ans++;
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