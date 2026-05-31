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
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    deque<int> dq;
    int mx = -1, idx = -1;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(mx < arr[i]){
            mx = arr[i];
            idx = i;
        }
        dq.push_back(arr[i]);
    }

    map<int, pair<int,int>> mp;
    for(int i=1;i<=idx;i++){
        int val1 = dq.front();
        dq.pop_front();
        int val2 = dq.front();
        dq.pop_front();
        mp[i] = {val1, val2};
        dq.push_back(min(val1, val2));
        dq.push_front(max(val1, val2));
    }

    while(q--){
        int k;
        cin >> k;

        if(k <= idx){
            cout << mp[k].first << " " << mp[k].second << endl;
        }
        else{
            int tmp = ((k-idx-1)%(n-1)) + 1;
            cout << dq[0] << " " << dq[tmp] << endl;
        }
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