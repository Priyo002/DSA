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
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> freq(n, 0);
    set<int> st;
    for(int i=0;i<=n;i++){
        st.insert(i);
    }

    int ans = INF;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
        if(freq[arr[i]] == 1){
            st.erase(arr[i]);
        }
        if(i-m>=0){
            freq[arr[i-m]]--;
            if(freq[arr[i-m]] == 0){
                st.insert(arr[i-m]);
            }
        }
        if(i>=m-1){
            ans = min(ans, *st.begin());
        }
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