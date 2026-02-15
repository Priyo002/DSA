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
vector<int> x, y, mxY, mnY;

bool check(int k){
    for(int i=0;i<n;i++){
        int idx = lower_bound(x.begin(), x.end(), x[i] + k) - x.begin();
        if(idx == n) return false;
        int mxDiff = max(abs(mnY[idx] - y[i]), abs(mxY[idx] - y[i]));
        if(mxDiff>=k) return true;
    }
    return false;
}

void solve(){
    cin >> n;

    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    x.assign(n, -1);
    y.assign(n, -1);
    mxY.assign(n, -1);
    mnY.assign(n, -1);

    for(int i=0;i<n;i++){
        x[i] = arr[i].first;
        y[i] = arr[i].second;
    }

    mxY = mnY = y;

    for(int i=n-2;i>=0;i--){
        mxY[i] = max(mxY[i], mxY[i+1]);
        mnY[i] = min(mnY[i], mnY[i+1]);
    }   

    int lo = 0, hi = 1e9;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
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