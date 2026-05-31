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

    vector<int> arr(n), pref(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        pref[i] = arr[i];
        if(i) pref[i] += pref[i-1];
    }

    set<int> st;
    st.insert(0);
    int tail = 0, head = -1;
    int ans = 0;

    while(tail<n){
        while(head+1<n && !st.count(pref[head+1])){
            head++;
            st.insert(pref[head]);
        }
        if(tail<=head){
            ans += (head - tail + 1);
        }
        if(tail<=head){
            if(tail == 0) st.erase(0);
            else st.erase(pref[tail-1]);
            tail++;
        }
        else{
            tail++;
            head = tail - 1;
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