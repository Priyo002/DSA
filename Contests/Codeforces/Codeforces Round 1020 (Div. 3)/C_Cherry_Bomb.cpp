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
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    int mn = LLONG_MAX, mx = LLONG_MIN;
    set<int> st;
    for(int i=0;i<n;i++){
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        if(b[i]!=-1){
            st.insert(a[i] + b[i]);
            if(st.size() > 1){
                cout << 0 << endl;
                return;
            }
        }
    }

    if(st.size()){
        int x = *st.begin();
        for(int i=0;i<n;i++){
            if(b[i] == -1){
                b[i] = x - a[i];
                if(b[i] < 0 || b[i] > k){
                    cout << 0 << endl;
                    return;
                }
            }
        }
        cout << 1 << endl;
    }
    else{ // All -1
        int lo = 0, hi = k;
        int ans = -1;
        while(lo<=hi){
            int mid = lo + (hi - lo)/2;
            int x = mx + mid;
            if(x - mn >= 0 && x - mn <= k){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        if(ans == -1) cout << 0 << endl;
        else cout << ans+1 << endl;
    }

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}