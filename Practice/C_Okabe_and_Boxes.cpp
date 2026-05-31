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

    stack<int> st;

    int curr = 1, ans = 0;
    
    for(int i=0;i<2*n;i++){
        string s;
        cin >> s;
        if(s == "remove"){
            if(st.size() && st.top() == curr){
                st.pop();
                curr++;
            }
            else{
                if(st.size()) ans++;
                while(st.size()) st.pop();
                curr++;
            }
        }
        else{
            int val;
            cin >> val;
            st.push(val);
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