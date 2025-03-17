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

    vector<vector<int>> arr(n);
    map<pair<int,int>,int> mp;

    for(int i=0;i<n;i++){
        int l,r;
        cin >> l >> r;
        arr[i] = {l,r,i};
        mp[{l,r}]++;
    }

    vector<int> ans(n,0);

    // calculate (r,R]
    sort(arr.begin(),arr.end(),[](vector<int>& a,vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });

    set<int> st;

    for(int i=0;i<n;i++){
        int l = arr[i][0];
        int r = arr[i][1];
        int idx = arr[i][2];
        if(mp[{l,r}] > 1){
            ans[idx] = 0;
        }
        else{
            auto it = st.lower_bound(r);
            if(it!=st.end()){
                ans[idx] += (*it - r);
            }
        }
        st.insert(r);
    }

    st.clear();

    // calculate [L,l)
    sort(arr.begin(),arr.end(),[](vector<int>& a,vector<int>& b){
        if(a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    });

    for(int i=n-1;i>=0;i--){
        int l = arr[i][0];
        int r = arr[i][1];
        int idx = arr[i][2];
        if(mp[{l,r}] > 1){
            ans[idx] = 0;
        }
        else{
            auto it = st.upper_bound(l);
            if(it!=st.begin()){
                it--;
                ans[idx] += (l - *it);
            }
        }
        st.insert(l);
    }

    for(auto &x : ans) cout << x << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}