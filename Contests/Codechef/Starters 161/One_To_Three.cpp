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
vector<vector<int>> dp1,dp2;

int f1(int i,bool flag){
    if(i == n-1){
        return 0;
    }

    if(dp1[flag][i]!=-1) return dp1[flag][i];

    int ans = arr[i] + f1(i+1,false);
    if(flag){
        if((4-arr[i-1]) + arr[i+1] == 4){
            ans = min(ans,4-arr[i] + f1(i+1,true));
        }
    }
    else{
        if(arr[i-1] + arr[i+1] == 4){
            ans = min(ans,4 - arr[i] + f1(i+1,true));
        }
    }
    return dp1[flag][i] = ans;
}

int f2(int i,bool flag){
    if(i == 0){
        return 0;
    }

    if(dp2[flag][i]!=-1) return dp2[flag][i];

    int ans = arr[i] + f2(i-1,false);
    if(flag){
        if(arr[i-1] + 4 - arr[i+1] == 4){
            ans = min(ans,4 - arr[i] + f2(i-1,true));
        }
    }
    else{
        if(arr[i-1] + arr[i+1] == 4){
            ans = min(ans,4 - arr[i] + f2(i-1,true));
        }
    }
    return dp2[flag][i] = ans;
}

void solve(){
    cin >> n;
    arr.assign(n,0);

    for(int i=0;i<n;i++) cin >> arr[i];

    dp1.assign(2,vector<int>(n,-1));
    dp2.assign(2,vector<int>(n,-1));

    cout << arr[0] + arr[n-1] + min(f1(1,false),f2(n-2,false)) << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}