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

    int ans = 0;
    deque<int> dq;
    for(int i=0;i<n;i++){
        while(dq.size() && dq.back()>=arr[i]){
            dq.pop_back();
        }
        dq.push_back(arr[i]);
        if(i-k>=0){
            if(dq.size() && dq.front() == arr[i-k]){
                dq.pop_front();
            }
        }
        if(i>=k-1){
            ans ^= dq.front();
        }
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