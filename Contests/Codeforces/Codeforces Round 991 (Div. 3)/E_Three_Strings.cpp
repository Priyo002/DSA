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

int n,m,l;
string a,b,c;

int dp[1010][1010];

int f(int i,int j,int k){
    if(i==n){
        int cnt = 0;
        for(int t1=j,t2 = k;t1<m;t1++,t2++){
            if(b[t1]!=c[t2]) cnt++;
        }
        return cnt;
    }
    if(j==m){
        int cnt = 0;
        for(int t1=i,t2 = k;t1<n;t1++,t2++){
            if(a[t1]!=c[t2]) cnt++;
        }
        return cnt;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = INF;

    if(a[i] == c[k]){
        ans = min(ans,f(i+1,j,k+1));
    }
    else{
        ans = min(ans,1 + f(i+1,j,k+1));
    }
    if(b[j] == c[k]){
        ans = min(ans, f(i,j+1,k+1));
    }
    else{
        ans = min(ans,1 + f(i,j+1,k+1));
    }

    return dp[i][j] = ans;
}

void solve(){
    cin >> a >> b >> c;

    n = a.size(), m = b.size();
    l = c.size();

    memset(dp,-1,sizeof(dp));

    cout << f(0,0,0) << endl;
}   

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}