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


vector<int> arr, pref;

void solve(){
    int n, q;
    cin >> n >> q;

    arr.assign(n, -1);
    pref.assign(n, 0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        pref[i] = arr[i];
        if(i) pref[i] += pref[i-1];
    }

    while(q--){
        int ch;
        cin >> ch;
        if(ch == 1){
            int x;
            cin >> x;
            x--;
            pref[x] = arr[x+1];
            if(x) pref[x] += pref[x-1];
            swap(arr[x], arr[x+1]);
        }
        else {
            int lq, rq;
            cin >> lq >> rq;
            lq--, rq--;
            int sum = pref[rq];
            if(lq) sum -= pref[lq - 1];
            cout << sum << endl;
        }
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}