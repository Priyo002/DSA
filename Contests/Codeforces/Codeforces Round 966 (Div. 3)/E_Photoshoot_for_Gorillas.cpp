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
    int n,m,k,w;
    cin >> n >> m >> k >> w;

    vector<vector<int>> pref(n+2,vector<int>(m+2,0));
    k--;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i+k<=n && j+k<=m){
                pref[i][j]++;
                pref[i][j+k+1]--;
                pref[i+k+1][j]--;
                pref[i+k+1][j+k+1]++;
            }
        }
    }

    vector<int> arr;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pref[i][j] += (pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]);
            arr.push_back(pref[i][j]);
        }
    }

    sort(arr.rbegin(),arr.rend());

    int ans = 0;
    vector<int> g(w);
    for(int i=0;i<w;i++) cin >> g[i];

    sort(g.rbegin(),g.rend());

    for(int i=0;i<w;i++) ans += g[i]*arr[i];
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