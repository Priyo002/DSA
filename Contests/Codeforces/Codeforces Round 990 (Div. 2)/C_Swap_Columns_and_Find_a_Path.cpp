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

void solve(){
    int n,m;
    cin >> m;
    n = 2;

    vector<vector<int>> arr(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    int sum = 0;
    for(int j=0;j<m;j++){
        sum += max(arr[0][j],arr[1][j]);
    }

    int ans = -INF;
    for(int j=0;j<m;j++){
        sum -= max(arr[0][j],arr[1][j]);
        ans = max(ans, sum + arr[0][j] + arr[1][j]);
        sum += max(arr[0][j],arr[1][j]);
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