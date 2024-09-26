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

int n,q;
vector<vector<int>> sparse;

void solve(){
    
    cin >> n >> q;

    int m = 30;

    sparse.assign(m+1,vector<int>(n+1,-1));

    for(int i=1;i<=n;i++){
        cin >> sparse[0][i];
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            sparse[i][j] = sparse[i-1][sparse[i-1][j]];
        }
    }

    while(q--){
        int x,k;
        cin >> x >> k;

        for(int i=0;i<=m;i++){
            if(k&(1LL<<i)){
                x = sparse[i][x];
            }
        }
        cout << x << endl;
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}