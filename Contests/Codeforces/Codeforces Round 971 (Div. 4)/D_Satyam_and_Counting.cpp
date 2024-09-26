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

    vector<pair<int,int>> arr(n);

    map<pair<int,int>,int> mp;

    int zeroY = 0, oneY = 0;

    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
        mp[arr[i]]++;
        if(arr[i].second) zeroY++;
        else oneY++;
    }

    int ans = 0;
    for(auto &z : arr){
        int x = z.first, y = z.second;
        if(y==0){
            int cnt = (zeroY-1)*(mp[{x,1}]);
            ans += cnt;
        }
        else{
            ans += ((mp[{x-1,y-1}]*mp[{x+1,y-1}]) >= 1LL ? 1LL : 0LL);
        }
    }

    for(auto &z : arr){
        int x = z.first, y = z.second;
        if(y==1){
            int cnt = (oneY-1)*(mp[{x,0}]);
            ans += cnt;
        }
        else{
            ans += ((mp[{x-1,y+1}]*mp[{x+1,y+1}]) >= 1LL ? 1LL : 0LL);
        }
    }

    cout << ans << endl;

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}