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
    int n;
    cin >> n;

    int n2 = (n*(n+1))%mod;
    n2 = ((n2%mod) * ((2*n+1)%mod))%mod;
    n2 = ((n2%mod) * (power(6,mod-2,mod)%mod))%mod;

    int n3 = ((n%mod)*((n-1)%mod))%mod;
    n3 = ((n3%mod)*((n+1)%mod))%mod;
    n3 = ((n3%mod)*(power(3,mod-2,mod)%mod))%mod;

    int ans = (n2+n3)%mod;

    ans = (2022*(ans%mod))%mod;

    cout << ans << endl;

}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}