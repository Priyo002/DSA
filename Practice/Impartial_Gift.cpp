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
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> arr(n), brr(m);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int j=0;j<m;j++){
        cin >> brr[j];
    }

    sort(arr.rbegin(), arr.rend());
    sort(brr.rbegin(), brr.rend());

    int i = 0, j = 0;
    while(i<n && j<m){
        if(arr[i] - brr[j] > d){
            i++;
        }
        else if(brr[j] - arr[i] > d){
            j++;
        }
        else{
            cout << arr[i] + brr[j];
            return;
        }
    }
    cout << -1;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}