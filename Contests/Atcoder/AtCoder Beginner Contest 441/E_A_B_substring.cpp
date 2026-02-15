#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

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

    string s;
    cin >> s;

    ordered_set st;
    st.insert({0, -1});

    int cntA = 0, cntB = 0, ans = 0;
    
    for(int i=0;i<n;i++){
        if(s[i] == 'A') cntA++;
        else if(s[i] == 'B') cntB++;
        int diff = cntA - cntB;
        int cnt = st.order_of_key({diff, -INF});
        ans += cnt;
        st.insert({diff, i});
    }
    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}