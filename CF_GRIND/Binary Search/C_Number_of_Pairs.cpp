#include<bits/stdc++.h>
using namespace std;
using pp = pair<int,int>;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<pp, null_type,less<pp>, rb_tree_tag,tree_order_statistics_node_update>

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
    int n,l,r;
    cin >> n >> l >> r;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    
    ordered_set st;
    int ans = 0;

    for(int i=0;i<n;i++){
        int lt = r-arr[i];
        int gt = l-arr[i];

        int n1 = st.order_of_key({lt+1,-1e18});
        int n2 = st.order_of_key({gt,-1e18});
       
        ans += max(0LL,n1-n2);

        st.insert({arr[i],i});
    }
    cout << ans << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}