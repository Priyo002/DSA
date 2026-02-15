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
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> a(n), b(m);
    map<int,int> freq1;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
        freq1[b[i]]++;
    }

    int len = (m-1)*p + 1;
    if(n < len){
        cout << 0;
        return;
    }

    vector<int> ans;
    vector<pair<int, map<int,int>>> arr(p, pair<int,map<int,int>>());
    for(int i=0;i<n;i++){
        if(freq1.count(a[i])){
            int idx = (i%p);
            int cnt = arr[idx].first;
            auto &freq2 = arr[idx].second;
            freq2[a[i]]++;
            if(freq1[a[i]] == freq2[a[i]]){
                cnt++;
            }
            arr[idx].first = cnt;
        }
        if(i-len>=0 && freq1.count(a[i-len])){
            int idx = ((i-len)%p);
            int cnt = arr[idx].first;
            auto &freq2 = arr[idx].second;
            if(freq1[a[i-len]] == freq2[a[i-len]]){
                cnt--;
            }
            freq2[a[i-len]]--;
            arr[idx].first = cnt;
        }
        if(i>=len-1){
            int stIdx = i-len+1;
            int idx = (stIdx%p);
            if(arr[idx].first == freq1.size()){
                ans.push_back(stIdx+1);
            }
        }
    }

    cout << ans.size() << endl;
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