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
    string s;
    cin >> s;

    int q;
    cin >> q;

    int n = s.size();
    vector<int> pref(n,0);

    for(int i=0;i<n-1;i++){
        if(s[i] == s[i+1]){
            pref[i] = 1;
        }
        if(i) pref[i] += pref[i-1];
    }

    while(q--){
        int l,r;
        cin >> l >> r;
        l--, r--;

        int sum = pref[r-1];
        if(l) sum -= pref[l-1];
        cout << sum << endl;
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