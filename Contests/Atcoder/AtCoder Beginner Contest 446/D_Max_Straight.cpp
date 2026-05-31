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
    
    map<int, int> freq;
    for(int i=0;i<n;i++){
        if(freq.count(arr[i]-1)){
            freq[arr[i]] = max(freq[arr[i]], freq[arr[i] - 1] + 1);
            freq.erase(arr[i] - 1);
        }
        else if(!freq.count(arr[i])){
            freq[arr[i]]++;
        }
    }

    int ans = 0;
    for(auto &x : freq){
        ans = max(ans, x.second);
    }

    freq.clear();

    for(int i=n-1;i>=0;i--){
        if(freq.count(arr[i]+1)){
            freq[arr[i]] = max(freq[arr[i]], freq[arr[i] + 1] + 1);
            freq.erase(arr[i] + 1);
        }
        else if(!freq.count(arr[i])){
            freq[arr[i]]++;
        }
    }

    for(auto &x : freq){
        ans = max(ans, x.second);
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