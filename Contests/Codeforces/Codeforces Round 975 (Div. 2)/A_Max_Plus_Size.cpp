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

int n;
vector<int> arr;
int dp[110][110][110];

int f(int i,int cnt,int idx){
    if(i>=n){
        if(idx==-1) return 0;
        return cnt+arr[idx];
    }
    if(dp[i][cnt][idx+1]!=-1) return dp[i][cnt][idx+1];
    int ans = f(i+1,cnt,idx);
    if(idx==-1){
        ans = max(ans,f(i+2,cnt+1,i));
    }
    else{
        if(arr[idx]<arr[i]){
            ans = max(ans,f(i+2,cnt+1,i));
        }
        else{
            ans = max(ans,f(i+2,cnt+1,idx));
        }
    }
    return dp[i][cnt][idx+1] = ans;
}

void solve(){
    
    cin >> n;
    arr.assign(n,0);

    for(int i=0;i<n;i++) cin >> arr[i];
    memset(dp,-1,sizeof(dp));

    cout << f(0,0,-1) << endl;

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}