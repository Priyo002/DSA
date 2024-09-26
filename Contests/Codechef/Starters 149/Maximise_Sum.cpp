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

    vector<int> arr(n);

    int sum = 0;
    bool flag = false;

    int mx = -INF, mn = INF;
    int cnt = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += abs(arr[i]);
        if(arr[i]==0) flag = true;
        if(arr[i]>0) mn = min(mn,arr[i]);
        if(arr[i]<0){
            cnt++;
            mx = max(mx,arr[i]);
        }
    }

    if(flag || mx==-INF || cnt%2==0){
        cout << sum << endl;
        return;
    }

    if(mn==INF){
        if(mx==-INF) mx = 0;
        sum -= abs(mx);
        sum += mx;
        cout << sum << endl;
        return;
    }

    if(abs(mn) < abs(mx)){
        sum -= mn;
        sum += -mn;
    }
    else{
        sum -= abs(mx);
        sum += mx;
    }
    cout << sum << endl;

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}