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

int n, c;
vector<int> arr;

bool check(int diff){
    int cnt = 1, last = arr[0];
    for(int i=1;i<n;i++){
        if(abs(arr[i] - last) >= diff){
            last = arr[i];
            cnt++;
            if(cnt>=c) return true;
        }
    }
    return (cnt>=c);
}

void solve(){
    cin >> n >> c;

    arr.assign(n, -1);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int lo = 0, hi = arr[n-1] - arr[0];
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
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