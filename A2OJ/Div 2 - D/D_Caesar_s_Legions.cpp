#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
const int mod = 1e8;
const long long INF = 1e18;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n1,n2,k1,k2;
int dp[11][11][101][101];

int f(int cntF,int cntH,int sF,int sH){

    if(cntF + cntH == n1 + n2) return 1;

    if(dp[sF][sH][cntF][cntH]!=-1) return dp[sF][sH][cntF][cntH];

    int ans = 0;
    if(cntF + 1 <= n1 && sF + 1 <= k1){
        ans += f(cntF + 1,cntH,sF + 1, 0);
    }
    if(cntH + 1 <= n2 && sH + 1 <= k2){
        ans += f(cntF, cntH + 1, 0, sH + 1);
    }
    ans %= mod;

    return dp[sF][sH][cntF][cntH] = ans;
}

void solve(){

    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp,-1,sizeof(dp));
    cout << f(0,0,0,0);
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();


    return 0;
}