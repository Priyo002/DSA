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
    int totalSum = 0;
    for(int &x : arr){
        cin >> x;
        totalSum += x;
        totalSum %= mod;
    }

    int leftSum = 0, ans = 0;
    for(int &x : arr){
        leftSum += x;
        leftSum %= mod;
        int rightSum = (totalSum - leftSum + mod)%mod;
        ans = (ans + ((x*rightSum)%mod))%mod;
    }
    cout << (ans%mod);
    
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}