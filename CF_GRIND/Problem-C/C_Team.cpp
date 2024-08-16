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

void solve(){
    int n,m;
    cin >> n >> m;

    if(n>m){
        if(n-1==m){
            string ans(n+m,' ');
            for(int i=0;i<n+m;i++){
                if(i%2==0) ans[i] = '0';
                else ans[i] = '1';
            }
            cout << ans << endl;
        }
        else{
            cout << -1 << endl;
            return;
        }
    }
    else{
        int lo = n-1;
        int hi = n+1;
        if(m>=lo && m<=2*hi){
            vector<string> ans(2*n+1,"");
            for(int i=1;i<2*n+1;i+=2){
                ans[i] = "0";
            }
            for(int i=2;i<2*n;i+=2){
                ans[i] = "1";
                m--;
            }
            if(m-2>=0){
                ans[0] = "11";
                m -= 2;
            }
            else if(m-1>=0){
                ans[0] = "1";
                m--;
            }
            if(m-2>=0){
                ans[2*n] = "11";
                m -= 2;
            }
            else if(m-1>=0){
                ans[2*n] = "1";
                m--;
            }
            for(int i=2;i<2*n;i+=2){
                if(m-1>=0){
                    ans[i].push_back('1');
                    m--;
                }
            }
            string s = "";
            for(auto str : ans) s += str;
            cout << s << endl;
        }
        else{
            cout << -1 << endl;
            return;
        }
    }
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