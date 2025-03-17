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

    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }

    int curr = arr[0].second;
    for(int i=1;i<n;i++){
        int diff = (arr[i].first - arr[i-1].first);
        curr -= diff;
        curr = max(curr,0LL);
        curr += arr[i].second;
    }
    cout << curr << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}