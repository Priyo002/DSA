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
    int n, s, k;
    cin >> n >> s >> k;
    
    set<int> st;
    bool flag = true;
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        st.insert(x);
        if(x == s){
            flag = false;
        }
    }

    if(flag){
        cout << 0 << endl;
        return;
    }

    for(int i=1;i<=2000;i++){
        if(!st.count(min(n, s + i)) || !st.count(max(1LL, s - i))){
            cout << i << endl;
            return;
        }
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