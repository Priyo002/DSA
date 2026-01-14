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

int getDigitSum(int n){
    int sum = 0;
    while(n>0){
        sum += (n%10);
        n /= 10;
    }
    return sum;
}

void solve(){
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + getDigitSum(dp[i-1]);
    }

    cout << dp[n];
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();


    return 0;
}