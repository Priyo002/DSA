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

int n;
vector<int> value,weight;
int dp[3001][3001];

int f(int i,int W){
    if(i==n) return 0;
    if(dp[i][W]!=-1) return dp[i][W];   

    int ans = f(i+1,W);
    for(int k=1;k<=3000;k++){
        if(weight[i]*k<=W){
            ans = max(ans,value[i]*k-(k*k) + f(i+1,W-weight[i]*k));
        }
        else break;
    }
    return dp[i][W] = ans;
}

void solve(){
    cin >> n;
    int W;
    cin >> W;

    value.assign(n,0);
    weight.assign(n,0);

    for(int i=0;i<n;i++){
        cin >> weight[i] >> value[i];
    }

    memset(dp,-1,sizeof(dp));

    cout << f(0,W) << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}