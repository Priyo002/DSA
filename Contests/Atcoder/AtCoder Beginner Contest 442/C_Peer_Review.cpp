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
    int n, m;
    cin >> n >> m;
    vector<set<int>> arr(n+1, set<int>());

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        arr[a].insert(b);
        arr[b].insert(a);
    }

    for(int i=1;i<=n;i++){
        int cnt = n - (int)arr[i].size() - 1;
        cout << (cnt*(cnt-1)*(cnt-2))/6 << " ";
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}