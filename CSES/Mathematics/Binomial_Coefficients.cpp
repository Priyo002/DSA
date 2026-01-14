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


vector<int> fact;

void precompute(){
    const int N = 1e6+2;
    fact.assign(N,1);
    fact[1] = 1;
    for(int i=2;i<N;i++){
        fact[i] = (fact[i-1] * i)%mod;
    }
}

int power(int a,int b,int MOD=1e9+7){
    int res = 1;
    while(b){
        if(b&1){
            res = ((res%MOD)*(a%MOD))%MOD;
        }
        a = ((a%MOD)*(a%MOD))%MOD;
        b = (b>>1);
    }
    return (res%MOD);
}

void solve(){
    int n,r;
    cin >> n >> r;

    int ans = (fact[n]%mod);
    ans *= power(fact[r],mod - 2);
    ans %= mod;
    ans *= power(fact[n-r],mod - 2);
    ans %= mod;
    cout << ans << endl;
}

int32_t main(){
    
    init();

    precompute();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}