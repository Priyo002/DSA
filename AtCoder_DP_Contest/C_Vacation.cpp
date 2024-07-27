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
vector<vector<int>> arr;

int dp[100100][4];

int f(int i,int prev){
    if(i==n) return 0;

    if(dp[i][prev]!=-1) return dp[i][prev];

    int ans = 0;
    for(int j=0;j<3;j++){
        if(j+1!=prev){
            ans = max(ans,arr[i][j]+f(i+1,j+1));
        }
    }

    return dp[i][prev] = ans;
}

void solve(){
    cin >> n;

    arr.clear();
    arr.resize(n,vector<int>(3));

    for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;

        arr[i][0] = a, arr[i][1] = b, arr[i][2] = c;
    }

    memset(dp,-1,sizeof(dp));

    cout << f(0,0) << endl;
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