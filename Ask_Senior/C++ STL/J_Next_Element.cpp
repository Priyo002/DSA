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

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    stack<int> st;
    vector<int> ngi(n);

    for(int i=n-1;i>=0;i--){
        while(st.size() && arr[st.top()]<=arr[i]) st.pop();
        if(st.size()) ngi[i] = st.top();
        else ngi[i] = -1;
        st.push(i);
    }

    int q;
    cin >> q;
    while(q--){
        int idx;
        cin >> idx;
        idx--;

        cout << ((ngi[idx] != -1) ? ngi[idx] + 1 : ngi[idx]) << endl;
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