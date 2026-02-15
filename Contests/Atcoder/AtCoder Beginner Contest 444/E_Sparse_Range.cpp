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

bool check(vector<int>& arr, map<int,int>& mp, int val, int k){
    if(mp.count(val)) return false;
    auto it = mp.upper_bound(val);
    if(it != mp.end() && it->first - val < k) return false;
    if(it!= mp.begin() && val - (--it)->first < k) return false;
    return true;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int tail = 0, head = -1, ans = 0;
    map<int, int> mp;
    while(tail<n){
        while(head + 1 < n && check(arr, mp, arr[head + 1], k)){
            head++;
            mp[arr[head]]++;
        }
        ans += (head - tail + 1);
        if(tail<=head){
            mp[arr[tail]]--;
            if(mp[arr[tail]] == 0) mp.erase(arr[tail]);
            tail++;
        }
        else {
            head = tail - 1;
            tail++;
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