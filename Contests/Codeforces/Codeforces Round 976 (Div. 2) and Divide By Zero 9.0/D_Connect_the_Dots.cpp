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

vector<int> parent,rankk;

void solve(){
    int n,m;
    cin >> n >> m;

    rankk.assign(n+1,1);
    parent.assign(n+1,0);
    for(int i=0;i<=n;i++) parent[i] = i;

    vector<vector<int>> arr(n+1);

    for(int i=0;i<m;i++){
        int a,d,k;
        cin >> a >> d >> k;
        arr[a] = 
    }



}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}