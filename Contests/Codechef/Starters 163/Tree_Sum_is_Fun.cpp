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

int n,x;

int check(int num){
    int sum = 0;
    int cnt = 0;
    while(num>=1){
        cnt++;
        sum += num;
        num /= 2;
        if(cnt >= x) break;
    }
    return sum;
}

void solve(){
    
    cin >> n >> x;

    int lo = 1, hi = 1e18;
    int ans = 0;

    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)>=n){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    if(check(ans) == n) cout << ans;
    else cout << -1;
    cout << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}