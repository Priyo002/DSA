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
int arr[3050];
int dp[3050][3050][2];

int f(int l,int r,bool flag){
    if(l>r) return 0;
    
    if(dp[l][r][flag]!=-1) return dp[l][r][flag];

    int ans;
    if(flag){
        ans = max(arr[l]+f(l+1,r,false),arr[r]+f(l,r-1,false));
    }
    else{
        ans = min(f(l+1,r,true),f(l,r-1,true));
    }

    return dp[l][r][flag] = ans;
}

void solve(){

    cin >> n;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }

    memset(dp,-1,sizeof(dp));

    int x = f(0,n-1,true);
    int y = sum - x;

    cout << x - y;
    
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