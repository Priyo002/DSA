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
    multiset<int> mt;
    int totalSum = 0;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        mt.insert(arr[i]);
        totalSum += arr[i];
    }

    vector<int> ans;

    for(int i=0;i<n;i++){
        int val = arr[i];
        mt.erase(mt.find(val));
        int leftOver = totalSum - val;
        int mx = *mt.rbegin();
        
        if(mx*2 == leftOver) ans.push_back(i+1);
        mt.insert(val);
    }

    cout << ans.size() << endl;
    for(int &x : ans) cout << x << " ";
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}