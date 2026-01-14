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
    int x;
    cin >> x;
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    int q;
    cin >> q;

    set<int> st;

    while(q--){
        int idx;
        cin >> idx;

        if(st.count(idx)){
            st.erase(idx);
            x -= arr[idx];
        }
        else{
            st.insert(idx);
            x += arr[idx];
        }
        cout << x << endl;
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();


    return 0;
}