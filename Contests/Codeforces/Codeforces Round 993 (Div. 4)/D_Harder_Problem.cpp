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
    set<int> st;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        st.insert(i+1);
    }

    vector<int> brr(n);
    for(int i=0;i<n;i++){
        if(st.count(arr[i])){
            st.erase(arr[i]);
            brr[i] = arr[i];
        }
        else{
            brr[i] = *st.begin();
            st.erase(st.begin());
        }
    }
    
    for(int &x : brr) cout << x << " ";
    cout << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}