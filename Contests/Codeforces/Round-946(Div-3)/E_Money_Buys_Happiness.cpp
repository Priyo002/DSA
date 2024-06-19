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

int m,x;
vector<int> cost,happiness;

map<string,int> dp;

int f(int i,int curr){
    if(i==m) return 0;

    string str = to_string(i)+ " " + to_string(curr);
    
    if(dp.find(str)!=dp.end()) return dp[str];

    int ans = 0;
    if(curr>=cost[i]){
        ans  = max(ans,happiness[i]+f(i+1,curr-cost[i]+x));
    }
    ans = max(ans,f(i+1,curr+x));

    return dp[str] = ans;
}

void solve(){
    cin >> m >> x;

    cost.clear();
    happiness.clear();
    cost.resize(m);
    happiness.resize(m);
    dp.clear();

    

    cout << f(0,0) << endl;

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