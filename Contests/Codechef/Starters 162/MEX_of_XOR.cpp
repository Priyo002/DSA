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

int l,r,x;

int f(int i,int loTight,int hiTight){
    if(i == 35) return 0;

    int lo = 0, hi = 1;

    int lbit = ((l>>i)&1);
    int rbit = ((r>>i)&1);

    if(loTight && lbit){
        lo = 1;
    }
    if(hiTight && !rbit){
        hi = 0;
    }

    int ans = 1e18;
    for(int j=lo;j<=hi;j++){
        int nLoTight = loTight, nHiTight = hiTight;
        if(j!=lbit) nLoTight = 0;
        if(j!=lbit) nHiTight = 0;

        ans = min(ans,(x^(j*(1LL<<i))) + f(i+1,loTight,hiTight));
    }

    return ans;
}

void solve(){

    int L,R;
    cin >> L >> R >> x;
    
    l = 0, R = L-1;
    int ans = f(1,1,1);
    l = R+1, R = 1e18;
    ans = min(ans,f(1,1,1));
    
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