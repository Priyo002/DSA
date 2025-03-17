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
    int n,k;
    cin >> n >> k;

    vector<int> fact(n+1);
    fact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i] = (i*fact[i-1])%mod;
    }

    set<pair<int,int>> st;

    for(int i=1;i<=n;i++){
        if(k-i>0 && i<k && k-i!=i && k-i<=n && st.count({i,k-i}) == 0 && st.count({k-i,i}) == 0){
            st.insert({i,k-i});
            st.insert({k-i,i});
        }
    }
    int cnt = st.size();
    int ans = (((cnt*(n-1))%mod)*fact[n-2])%mod;
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