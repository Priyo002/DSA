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
    for(int &x : arr){
        cin >> x;
    }

    int ans = 0;
    for(int i=0;i<(1<<n);i++){
        long double currPos = 0.5;
        int cnt = 0;
        // bit -> 1 (+), 0 (-)
        for(int j=0;j<n;j++){
            if((i&(1<<j))){
                long double newPos = currPos + (long double)arr[j];
                long double l = min(currPos, newPos);
                long double r = max(currPos, newPos);
                if(l<=0.0 && r>=0.0){
                    cnt++;
                }
                currPos = newPos;
            }
            else{
                long double newPos = currPos - (long double)arr[j];
                long double l = min(currPos, newPos);
                long double r = max(currPos, newPos);
                if(l<=0.0 && r>=0.0){
                    cnt++;
                }
                currPos = newPos;
            }
        }
        ans = max(ans, cnt);
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