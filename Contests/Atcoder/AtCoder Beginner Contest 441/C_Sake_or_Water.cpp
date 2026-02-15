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
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> arr(n);
    for(int &y : arr){
        cin >> y;
    }

    sort(arr.begin(), arr.end());

    int idx = -1, temp = 0;
    for(int i=k-1;i>=0;i--){
        temp += arr[i];
        if(temp >= x){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        cout << -1;
    } 
    else{
        cout << (k - 1 - idx + 1) + n - k;
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