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

int f(int &e, int &f){
    int cnt = 0;
    while(e >= 2 && f >= 1){
        cnt += 3;
        e -= 2;
        f--;
    }
    return cnt;
}

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    int ta = a, tb = b, tc = c;

    int way1 = f(tb, ta) + f(tc, tb);
    int way2 = f(c, b) + f(b, a);

    cout << max(way1, way2) << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    return 0;
}