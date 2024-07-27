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

void solve(){
    int n, m, k; 
    cin >> n >> m >> k;

    string str;
    cin >> str;

    vector<int> s(n+2);
    for(int i=1;i<=n;i++) s[i] = str[i-1];

    vector<int> dp(n + 2, 1e18);

    dp[0] = 0;

    for (int i = 1; i <= n + 1; i++) {

        if (i != n + 1 && s[i] == 'C') continue;

        for (int t = 1; t <= m; t++){
            if (i - t >= 0 && (i - t == 0 || s[i - t] == 'L')){
                dp[i] = min(dp[i], dp[i - t]);
            }
        }

        if (i>1 && s[i - 1] == 'W'){ 
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }
    }

    if (dp[n + 1] <= k) cout << "YES";
    else cout << "NO";

    cout << endl;
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