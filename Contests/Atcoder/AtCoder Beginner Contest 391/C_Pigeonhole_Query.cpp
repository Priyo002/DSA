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

void solve(){
    int n;
    cin >> n;
    int q;
    cin >> q;

    vector<int> arr(n+1,1);
    int cnt = 0;
    while(q--){
        int ch;
        cin >> ch;
        if(ch == 1){
            int a,b;
            cin >> a >> b;
            if(arr[a] == 0) continue;
            arr[a]--;
            if(arr[a] == 1) cnt--;
            arr[b]++;
            if(arr[b] == 2) cnt++;
        }
        else{
            cout << cnt << endl;
        }
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}