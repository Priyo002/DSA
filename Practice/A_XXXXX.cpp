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
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    int sum = 0, leftIdx = -1, rightIdx = n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
        if(arr[i]%x != 0){
            if(leftIdx == -1) leftIdx = i;
            rightIdx = i;
        }
    }

    if(sum%x != 0) cout << n;
    else if(leftIdx == -1) cout << -1;
    else cout << max(n - leftIdx - 1, rightIdx);
    cout << endl;

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    return 0;
}