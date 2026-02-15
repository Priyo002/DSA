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

vector<int> arr;

void solve(){
    int n, k;
    cin >> n >> k;

    int x, a, b, c;
    cin >> x >> a >> b >> c;

    arr.clear();
    arr.push_back(x);
    for(int i=1;i<=n-1;i++){
        int val = ((a*arr.back() + b)%c);
        arr.push_back(val);
    }

    // block pref and suff OR calculation
    // idx -> [0, 1, 2, 3, 4, 5], k = 3 (block size)
    // [0, 1, 2] [3, 4, 5]
    vector<int> pref(n), suff(n);
    for(int i=0;i<n;i++){
        if(i%k == 0){
            pref[i] = arr[i];
        }
        else{
            pref[i] = (arr[i]|pref[i-1]);
        }
    }

    for(int i=n-1;i>=0;i--){
        if(i==n-1 || (i%k == k-1)){
            suff[i] = arr[i];
        }
        else{
            suff[i] = (arr[i]|suff[i+1]);
        }
    }

    int ans = 0;
    for(int st=0;st+k-1<n;st++){
        int en = st+k-1;
        int windowOr = (suff[st]|pref[en]);
        ans ^= windowOr;
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