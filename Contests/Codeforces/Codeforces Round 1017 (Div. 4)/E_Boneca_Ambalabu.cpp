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

    vector<int> arr(n), one(31,0), zero(31,0);
    for(int &x : arr){
        cin >> x;
        for(int i=0;i<30;i++){
            if((x>>i)&1) one[i]++;
            else zero[i]++;
        }
    }

    int ans = 0;

    for(int &x : arr){
        int sum = 0;
        for(int i=0;i<30;i++){
            if((x>>i)&1){
                sum += (zero[i] * (1LL<<i));
            }
            else{
                sum += (one[i] * (1LL<<i));
            }
        }
        ans = max(ans, sum);
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