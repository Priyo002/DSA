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

int f(int a,int b,int c,int d){
    int ans = 0;
    
    return ans;
}

void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int ans = 0;

    if(a>c && b>d) ans++;
    else if(a>c && b==d) ans++;
    else if(a==c && b>d) ans++;

    if(a>d && b>c) ans++;
    else if(a>d && b==c) ans++;
    else if(a==d && b>c) ans++;

    if(b>c && a>d) ans++;
    else if(b==c && a>d) ans++;
    else if(b>c && a==d) ans++;

    if(b>d && a>c) ans++;
    else if(b==d && a>c) ans++;
    else if(b>d && a==c) ans++;
    
    cout << ans << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}