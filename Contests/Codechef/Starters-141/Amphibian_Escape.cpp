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

int n,k,h;

bool check(int a,int b){
    return ((a*k)-(b*(k-1)))>=h;
}


void solve(){
    cin >> n >> k >> h;

    int ans = 0;
    for(int a=1;a<=n;a++){
        if(a>=h){
            ans += n;
        }
        else{
            int lo = 1, hi = a-1;
            int b = 0;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(check(a,mid)){
                    b = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            ans += b;
        }
    }

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