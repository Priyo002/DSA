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
vector<long double> p;

int done[3003][3003];
long double dp[3003][3003];

long double f(int i,int h){
    if(i==n) return h>(n-h);//head>tail

    if(done[i][h]) return dp[i][h];

    long double ans = p[i]*f(i+1,h+1);
    ans += (1-p[i])*f(i+1,h);

    done[i][h] = 1;
    return dp[i][h] = ans;
}

void solve(){
    cin >> n;

    p.resize(n);
    memset(done,0,sizeof(done));

    for(int i=0;i<n;i++) cin >> p[i];

    cout << setprecision(9) << f(0,0) << endl;
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