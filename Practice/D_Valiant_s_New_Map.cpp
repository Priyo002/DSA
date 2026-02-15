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

int n, m;
vector<vector<int>> arr;

bool check(int l){

    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            pref[i+1][j+1] = (arr[i][j]>=l);
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pref[i][j] += (pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1]);
        }
    }

    for(int i=l;i<=n;i++){
        for(int j=l;j<=m;j++){
            int cnt = pref[i][j];
            cnt -= pref[i][j-l];
            cnt -= pref[i-l][j];
            cnt += pref[i-l][j-l];
            if(cnt == l*l) return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;

    arr.assign(n, vector<int>(m, -1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    int lo = 1, hi = min(n, m);
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    cout << ans << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    return 0;
}