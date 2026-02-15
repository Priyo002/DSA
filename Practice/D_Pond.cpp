#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

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

int n, k;
vector<vector<int>> arr;

bool check(int val){

    vector<vector<int>> grid(n, vector<int>());

    for(int i=0;i<n;i++){
        multiset<int> mt;
        for(int j=0;j<n;j++){
            if(arr[i][j]<=val){
                mt.insert(arr[i][j]);
            }
            if(j-k>=0 && arr[i][j-k]<=val){
                mt.erase(mt.find(arr[i][j-k]));
            }
            if(j>=k-1){
                grid[i].push_back(mt.size());
            }
        }
    }

    for(int j=0;j<grid[0].size();j++){
        int totalCnt = 0;
        for(int i=0;i<n;i++){
            totalCnt += grid[i][j];
            if(i-k>=0){
                totalCnt -= grid[i-k][j];
            }
            if(i>=k-1){
                if(totalCnt>=((k*k) + 1)/2) return true;
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> k;
    
    arr.assign(n, vector<int>(n, -1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

    int lo = 0, hi = 1e9;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
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