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
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> distPref(n), distSuff(n);
    distPref[0] = 0;
    
    for(int i=0;i<n-1;i++){
        int nextDist = arr[i+1] - arr[i];
        int prevDist = arr[i] - arr[i-1];
        if(i==0) prevDist = INF;
        if(nextDist <= prevDist){
            distPref[i+1] = 1 + distPref[i];
        }
        else{
            distPref[i+1] = nextDist + distPref[i];
        }
    }

    distSuff[n-1] = 0;
    for(int i=n-1;i>=1;i--){
        int prevDist = arr[i+1] - arr[i];
        int nextDist = arr[i] - arr[i-1];
        if(i==n-1) prevDist = INF;
        if(nextDist <= prevDist){
            distSuff[i-1] = 1 + distSuff[i];
        }
        else{
            distSuff[i-1] = nextDist + distSuff[i];
        }
    }

    // for(auto &x : distPref) cout << x << " ";
    // cout << endl;
    // for(auto &x : distSuff) cout << x << " ";
    // cout << endl;

    int m;
    cin >> m;

    while(m--){
        int l,r;
        cin >> l >> r;
        l--, r--;
        if(l<r){
            int ans = distPref[r];
            ans -= distPref[l];
            cout << ans;
        }
        else{
            int ans = distSuff[l];
            ans -= distSuff[r];
            cout << abs(ans);
        }
        cout << endl;
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}