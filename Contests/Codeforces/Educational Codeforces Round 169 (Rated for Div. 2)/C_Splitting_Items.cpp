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
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr.rbegin(),arr.rend());

    for(int i=1;i<n;i+=2){
        if(arr[i]+k>=arr[i-1]){
            k -= (arr[i-1]-arr[i]);
            arr[i] = arr[i-1];
        }
        else{
            arr[i] += k;
            break;
        }
    }
    int a = 0, b = 0;
    for(int i=0;i<n;i++){
        if(i&1) b+= arr[i];
        else a += arr[i];
    }
    cout << a-b << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}
