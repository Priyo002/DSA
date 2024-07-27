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
    int n;
    cin >> n;

    vector<int> arr(63,0);
    for(int i=0;i<=62;i++){
        if((n>>i)&1) arr[i] = 1;
    }

    vector<int> ans;
    ans.push_back(n);

    for(int i=0;i<=62;i++){
        if(arr[i]==1){
            int val = 0;
            for(int j=0;j<=62;j++){
                if(i==j) continue;
                if(arr[j]) val |= (1LL<<j);
            }
            if(val) ans.push_back(val);
        }
    }

    reverse(ans.begin(),ans.end());

    set<int> st;
    st.insert(n);

    for(int i=1;i<ans.size();i++){
        st.insert((ans[i]|ans[i-1]));
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
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