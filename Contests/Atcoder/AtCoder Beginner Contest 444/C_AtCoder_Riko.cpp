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

bool check(int L, int n, vector<int>& arr) {
    int i = 0, j = n - 1;
    while(i<=j){
        if(arr[j] == L) j--;
        else if(i<j && arr[i] + arr[j] == L) i++, j--;
        else return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &x : arr) cin >> x;

    sort(arr.begin(), arr.end());

    set<int> st;
    st.insert(arr[n-1]);
    for(int i=1;i<n;i++){
        int temp = arr[0] + arr[i];
        if(!st.count(temp) && arr[n-1]<=temp){
            st.insert(temp);
        }
    }

    vector<int> ans;
    for(auto &x : st){
        if(check(x, n, arr)){
            ans.push_back(x);
        }
    }

    for(int &x : ans){
        cout << x << " ";
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