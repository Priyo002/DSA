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

void solve(){
    int n,x;
    cin >> n >> x;

    vector<int> arr(n),pref(n),dp(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        pref[i] = arr[i];
        if(i) pref[i] += pref[i-1];
    }


    for(int i=n-1;i>=0;i--){
        int lo = i, hi = n-1;
        int idx = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int sum = pref[mid];
            if(i) sum -= pref[i-1];
            if(sum<=x){
                idx = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        if(idx!=-1){
            dp[i] = (idx-i+1);
            if(idx+2<n) dp[i] += dp[idx+2];
        }
        else{
            if(i+1<n) dp[i] = dp[i+1];
        }
    }

    int ans = accumulate(dp.begin(),dp.end(),0LL);
    cout << ans << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}