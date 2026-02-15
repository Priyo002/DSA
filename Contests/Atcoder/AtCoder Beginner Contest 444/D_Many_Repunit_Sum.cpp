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

    vector<int> arr(n);
    int mx = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    vector<int> pref(mx + 100, 0);

    for(int i=0;i<n;i++){
        pref[0]++;
        pref[arr[i]]--;
    }

    for(int i=1;i<mx+100;i++){
        pref[i] += pref[i-1];
    }

    int carry = 0;
    string ans = "";
    for(int i=0;i<mx;i++){
        int sum = (pref[i] + carry);
        ans += to_string((sum%10));
        sum /= 10;
        carry = sum;
    }
    reverse(ans.begin(), ans.end());
    if(carry) ans = to_string(carry) + ans;
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