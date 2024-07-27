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
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

string s1,s2;
int n,m;
int dp[3001][3001];
int back[3001][3001];

int f(int i,int j){
    if(i==n || j==m) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    if(s1[i]==s2[j]){
        if(ans<1+f(i+1,j+1)){
            ans = 1+f(i+1,j+1);
            back[i][j] = 1;
        }
    }
    else{
        if(ans<f(i+1,j)){
            ans = f(i+1,j);
            back[i][j] = 2;
        }
        if(ans<f(i,j+1)){
            ans = f(i,j+1);
            back[i][j] = 3;
        }
    }

    return dp[i][j] = ans;
}

void generate(int i,int j){
    if(i==n || j==m) return;
    
    int ch = back[i][j];
    if(ch==1){
        cout << s1[i];
        generate(i+1,j+1);
    }
    else if(ch==2){
        generate(i+1,j);
    }
    else if(ch==3){
        generate(i,j+1);
    }
}

void solve(){
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();

    memset(dp,-1,sizeof(dp));

    f(0,0);
    generate(0,0);
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}