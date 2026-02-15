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

    vector<vector<int>> arr(n+1, vector<int>());
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr[x].push_back(i+1);
    }

    int q;
    cin >> q;

    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        if(arr[x].size() == 0){
            cout << 0 << endl;
            continue;
        }
        int cnt = upper_bound(arr[x].begin(), arr[x].end(), r) - upper_bound(arr[x].begin(), arr[x].end(), l-1);
        cout << cnt << endl;
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}