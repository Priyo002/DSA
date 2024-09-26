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
    int m;
    cin >> m;

    vector<int> arr;

    while(m>0){
        arr.push_back(m%3);
        m /= 3;
    }

    vector<int> ans;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i];j++){
            ans.push_back(i);
        }
    }


    cout << (int)ans.size() << endl;
    for(auto &x : ans){
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