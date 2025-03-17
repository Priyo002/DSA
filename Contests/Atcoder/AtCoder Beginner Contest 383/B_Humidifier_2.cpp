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
    int n,m,d;
    cin >> n >> m >> d;

    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            if(s[j] == '.') arr.push_back({i,j});
        }
    }

    int ans = 2;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            int cnt = 0;
            for(int k=0;k<arr.size();k++){
                if(k == i || k == j) continue;
                int dist1 = abs(arr[k].first - arr[i].first) + abs(arr[k].second - arr[i].second);
                int dist2 = abs(arr[k].first - arr[j].first) + abs(arr[k].second - arr[j].second);
                if(dist1<=d || dist2<=d) cnt++;
            }
            ans = max(ans,cnt + 2);
        }
    }
    cout << ans << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}