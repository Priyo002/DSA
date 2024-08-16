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

vector<int> arr;

bool check(int n,int k){
    int cnt = n;
    auto lt = upper_bound(arr.begin(),arr.end(),n) - arr.begin();
    cnt -= lt;
    return cnt>=k;
}

void solve(){
    int n,q;
    cin >> n >> q;

    arr.resize(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    while(q--){
        int k;
        cin >> k;
        
        int lo = 1, hi = LLONG_MAX;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,k)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        cout << ans << endl;
    }
    
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