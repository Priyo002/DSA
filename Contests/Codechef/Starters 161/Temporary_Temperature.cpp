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

int n,k;
vector<int> temp;

bool check(int diff){

    vector<pair<int,int>> intervals;
    for(auto &x : temp){
        intervals.push_back({x-diff,x+diff});
    }

    vector<pair<int,int>> arr;
    arr.push_back(intervals[0]);
    int cnt = 0;

    for(int i=1;i<n;i++){
        int lo = max(arr.back().first,intervals[i].first);
        int hi = min(arr.back().second,intervals[i].second);

        if(lo > hi){
            cnt++;
            arr.push_back(intervals[i]);
        }
        else{
            arr.push_back({lo,hi});
        }
    }
    return cnt <= k;
}

void solve(){
    cin >> n >> k;

    temp.assign(n,0);
    for(int i=0;i<n;i++) cin >> temp[i];

    int lo = 0, hi = 2e10;
    int ans = -1;

    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
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