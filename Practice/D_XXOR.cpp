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
    int n, k;
    cin >> n >> k;

    vector<int> arr(61, 0), temp;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        temp.push_back(x);
        for(int j=0;j<61;j++){
            if(((x>>j)&1)){
                arr[j]++;
            }
        }
    }

    int val = 0;
    for(int i=60;i>=0;i--){
        int cntOne = arr[i], cntZero = n - arr[i];
        if(cntZero >= cntOne && ((val|(1LL<<i)) <= k)){
            val |= (1LL<<i);
        }
    }
    
    int ans = 0;
    for(int &x : temp){
        ans += (x^val);
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