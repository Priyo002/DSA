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

int n, m, q;
vector<int> arr, brr, prefA, prefB;

int getSum(int k, int z){
    return prefA[k] + prefB[z-k];
}

bool check(int m1, int m2, int z){
    return getSum(m1, z) < getSum(m2, z);
}

void solve() {

    cin >> n >> m >> q;

    arr.assign(n, -1);
    brr.assign(m, -1);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<m;i++){
        cin >> brr[i];
    }

    sort(arr.rbegin(), arr.rend());
    sort(brr.rbegin(), brr.rend());

    prefA.assign(n+1, 0);
    prefB.assign(m+1, 0);
    for (int i=0;i<n;i++){
        prefA[i+1] = prefA[i] + arr[i];
    }
    
    for(int i=0;i<m;i++){
        prefB[i+1] = prefB[i] + brr[i];
    }

    while(q--){
        int x, y, z;
        cin >> x >> y >> z;

        int lo = max({0LL, z - y, z - m});
        int hi = min({n, x, z});
        
        if(lo>hi){
            cout << 0 << endl;
            continue;
        }
        
        while(hi-lo>=3){
            int m1 = lo + (hi - lo)/3;
            int m2 = hi - (hi - lo)/3;
            if(check(m1, m2, z)){
                lo = m1;
            }
            else{
                hi = m2;
            }
        }

        int ans = 0;
        for (int i=lo;i<=hi;i++){
            ans = max(ans, getSum(i, z));
        }

        cout << ans << endl;
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    return 0;
}