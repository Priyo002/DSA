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
    int n;
    cin >> n;

    int cnt = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x == i+1){
            cnt++;
        }
    }
    if(cnt == 0){
        cout << n - 2 << endl;
    }
    else{
        cout << (n - (cnt == n ? 0 : 1)) << endl;
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