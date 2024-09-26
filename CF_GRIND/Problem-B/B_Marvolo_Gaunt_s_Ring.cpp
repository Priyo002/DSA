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
    int n,p,q,r;
    cin >> n >> p >> q >> r;
    
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> prefMax(n),prefMin(n),suffMax(n),suffMin(n);
    
    for(int i=0;i<n;i++){
        prefMax[i] = arr[i];
        prefMin[i] = arr[i];
        if(i){
            prefMax[i] = max(prefMax[i-1],prefMax[i]);
            prefMin[i] = min(prefMin[i-1],prefMin[i]);
        }
    }

    for(int i=n-1;i>=0;i--){
        suffMax[i] = arr[i];
        suffMin[i] = arr[i];
        if(i+1<n){
            suffMax[i] = max(suffMax[i+1],suffMax[i]);
            suffMin[i] = min(suffMin[i+1],suffMin[i]);
        }
    }

    int ans = LLONG_MIN;
    for(int i=0;i<n;i++){
        int t1 = max(p*prefMax[i],p*prefMin[i]);
        int t2 = max(r*suffMax[i],r*suffMin[i]);
        ans = max(ans,t1 + t2 + (q*arr[i]));
    }
    cout << ans << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}