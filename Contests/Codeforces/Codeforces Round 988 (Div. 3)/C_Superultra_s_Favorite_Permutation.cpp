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

    if(n<=4){
        cout << -1 << endl;
        return;
    }
    else{
        vector<int> ans;
        for(int i=2;i<=n;i+=2){
            if(i==4) continue;
            ans.push_back(i);
        }
        ans.push_back(4);
        ans.push_back(5);
        for(int i=1;i<=n;i+=2){
            if(i==5) continue;
            ans.push_back(i);
        }
        for(auto &x : ans) cout << x << " ";
        cout << endl;
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