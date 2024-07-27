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

int n;
int arr[1001];

int dp[101000];

int f(int k){

    if(k==0) return 0;

    if(dp[k]!=-1) return dp[k];

    int ans = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k && f(k-arr[i])==0) ans = 1;
    }

    return dp[k] = ans;
}

void solve(){
    int k;
    cin >> n >> k;

    for(int i=0;i<n;i++) cin >> arr[i];

    memset(dp,-1,sizeof(dp));

    if(f(k)) cout << "First";
    else cout << "Second";
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}