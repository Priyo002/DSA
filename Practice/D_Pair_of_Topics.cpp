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

// ai + aj > bi + bj
// ai - bi + aj - bj > 0

void solve(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }

    vector<int> c(n);
    for(int i=0;i<n;i++){
        c[i] = a[i] - b[i];
    }

    sort(c.begin(), c.end());

    int i = 0, j = n-1;
    int ans = 0;
    while(i<j){
        if(c[i] + c[j] > 0){
            ans += (j - i);
            j--;
        }
        else{
            i++;
        }
    }
    cout << ans;

}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}