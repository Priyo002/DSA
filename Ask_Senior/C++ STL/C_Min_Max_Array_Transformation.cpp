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

    vector<int> arr(n), brr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<n;i++) cin >> brr[i];

    for(int i=0;i<n;i++){
        int ele = *lower_bound(brr.begin(),brr.end(),arr[i]);
        cout << ele - arr[i] << " ";
    }
    cout << endl;

    int lastIdx = n-1;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        int idx = lower_bound(brr.begin(),brr.end(),arr[i]) - brr.begin();
        int len = lastIdx - idx + 1;
        if(len > 1){
            ans.push_back(brr[lastIdx] - arr[i]);
        }
        else{
            ans.push_back(brr[lastIdx] - arr[i]);
            lastIdx = idx-1;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int &x : ans) cout << x << " ";
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