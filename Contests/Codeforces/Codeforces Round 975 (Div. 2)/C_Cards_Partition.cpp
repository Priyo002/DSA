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

int n,k;
vector<int> arr;

void solve(){
    cin >> n >> k;

    arr.assign(n,0);

    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin(),arr.end());
    
    int mx = arr[n-1];

    int ans = 1;
    for(int i=1;i<=n;i++){
        int rem = (sum+k)/i;
        if(!(rem+1<=mx || rem*i+1<=sum)){
            ans = i;
        }
    }
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