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
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

bool check(int k,int n){
    if(k+1>(int)sqrtl(LLONG_MAX)) return false;
    int sum = (k*(k+1))/2;
    return sum<=n;
}

void solve(){
    int n;
    cin >> n;

    int lo = 1, hi = 1e18;

    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid,n+1)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << n-ans+1 << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}