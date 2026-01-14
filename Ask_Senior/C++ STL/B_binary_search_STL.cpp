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
    int n,q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int &x : arr) cin >> x;

    sort(arr.begin(),arr.end());

    while(q--){
        string s;
        cin >> s;
        int x;
        cin >> x;
        if(s == "binary_search"){
            if(binary_search(arr.begin(),arr.end(),x)) cout << "found";
            else cout << "not found";
        }
        else if(s == "lower_bound"){
            auto it = lower_bound(arr.begin(),arr.end(),x);
            if(it == arr.end()) cout << -1;
            else cout << *it;
        }
        else{
            auto it = upper_bound(arr.begin(),arr.end(),x);
            if(it == arr.end()) cout << -1;
            else cout << *it;
        }
        cout << endl;
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}