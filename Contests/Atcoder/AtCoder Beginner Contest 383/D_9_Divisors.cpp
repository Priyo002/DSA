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

bool f(int n){
    int cnt = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            int comp = n/i;
            cnt += 2;
            if(comp == i){
                cnt--;
            }
        }
        if(cnt>9) return false;
    }
    return (cnt == 9);
}

void solve(){
    int n;
    cin >> n;

    int ans = 0;

    for(int i=1;i*i<n;i++){
        if(f(i*i)){
            ans++;
        }
    }
    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}