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

    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }

    for(int i=0;i<n;i++){
        if(i){
            if(arr[i].first < arr[i-1].first || arr[i].second < arr[i-1].second){
                cout << "NO" << endl;
                return;
            }
            int diff1 = arr[i].first - arr[i-1].first;
            int diff2 = arr[i].second - arr[i-1].second;
            if(diff1 < diff2){
                cout << "NO" << endl;
                return;
            }
        }
        if(arr[i].second > arr[i].first){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    return 0;
}