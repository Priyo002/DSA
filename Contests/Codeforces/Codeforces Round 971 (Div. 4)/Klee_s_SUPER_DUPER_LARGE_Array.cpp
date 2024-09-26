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
const long long INF = 3e18;

void init(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,a,total;

int f(int k){
    int first = (2*a + (k-1))*k;
    first /= 2;
    int second = total - first;
    int temp = abs(first-second);
    return temp;
}

bool check(int mid){
    if(mid==n) return true;
    int curr1 = f(mid);
    int curr2 = f(mid+1);
    return curr1<=curr2;
}

void solve(){
    
    cin >> n >> a;

    total = (2*a + (n-1))*n;
    total /= 2;

    int lo = 1, hi = n;

    int ans = INF;

    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid)){
            ans = min(ans,f(mid));
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
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