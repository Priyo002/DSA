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

int n,W;
vector<pair<int,int>> arr;
int dp[101][100100];

int f(int i,int left){

    if(i==n) return 0;

    if(dp[i][left]!=-1) return dp[i][left];

    int ans = f(i+1,left);
    if(left-arr[i].first>=0){
        ans = max(ans,arr[i].second+f(i+1,left-arr[i].first));
    }

    return dp[i][left] = ans;
}

void solve(){
    cin >> n >> W;

    arr.clear();
    arr.resize(n);

    for(int i=0;i<n;i++){
        int w,v;
        cin >> w >> v;
        arr[i].first = w;
        arr[i].second = v;
    }

    memset(dp,-1,sizeof(dp));

    cout << f(0,W) << endl;
    
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