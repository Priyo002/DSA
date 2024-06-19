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
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

void solve(){
    int n,l,r,x;
    cin >> n >> l >> r >> x;

    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    int cnt = 0;
    for(int i=0;i<=((1LL<<n)-1);i++){
        int bit = 0;
        int sum = 0, mn = INT_MAX, mx = INT_MIN;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                mn = min(mn,arr[j]);
                mx = max(mx,arr[j]);
                sum += arr[j];
                bit++;
            }
        }
        if(bit>=2){
            if(sum>=l && sum<=r && mx-mn>=x){
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}