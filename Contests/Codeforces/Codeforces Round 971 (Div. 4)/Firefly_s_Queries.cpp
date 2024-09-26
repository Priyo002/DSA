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
    int n, q; 
    cin >> n >> q;
 
    vector<int>arr(n);
    for(auto &i : arr) cin >> i;

    vector<int>prefix(n + 1);

    for(int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    auto calcPre = [&](int shift, int index) -> int {
        pair<int,int>range = {(shift) % n, (index + shift) % n};
        range.first++, range.second++;

        if(range.first <= range.second) {
            return prefix[range.second] - prefix[range.first - 1];
        }
        
        return prefix[range.second] + (prefix[n] - prefix[range.first - 1]);
    };
 
    auto calcSuff = [&](int shift, int index) -> int {
        pair<int,int>range = {(index + shift) % n, (n - 1 + shift) % n};
        range.first++, range.second++;

        if(range.first <= range.second) {
            return prefix[range.second] - prefix[range.first - 1];
        }
        
        return prefix[range.second] + (prefix[n] - prefix[range.first - 1]);
    };

    auto calcRange = [&](int shift, int left, int right) -> int {
        pair<int,int>range = {(left + shift) % n, (right + shift) % n};
        range.first++, range.second++;

        if(range.first <= range.second) {
            return prefix[range.second] - prefix[range.first - 1];
        }
        return prefix[range.second] + (prefix[n] - prefix[range.first - 1]);
    };

    for(int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; 
        int firstArr = (l - 1) / n, lastArr = (r - 1) / n;
        if(firstArr == lastArr) cout << calcRange(firstArr, l - 1, r - 1) << "\n";
        else cout << (lastArr - firstArr - 1) * prefix[n] + calcSuff(firstArr, l - 1) + calcPre(lastArr, r - 1) << "\n";
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