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

int n;
vector<int> arr;

bool check1(int mx){
    int extra = 0;
    for(auto &x : arr){
        if(x>mx){
            extra += (x-mx);
        }
        else{
            extra -= (mx-x);
            extra = max(0LL,extra);
        }
    }
    extra = max(0LL,extra);
    return extra==0;
}

bool check2(int mn){
    int extra = 0;
    for(auto &x : arr){
        if(x<mn){
            if(extra<(mn-x)) return false;
            extra -= (mn-x);
        }
        else{
            extra += (x-mn);
        }
    }
    return true;
}

void solve(){

    cin >> n;

    arr.assign(n,0);
    for(int i=0;i<n;i++) cin >> arr[i];

    int lo = 0, hi = 1e18;
    int miniMax = hi;

    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check1(mid)){
            miniMax = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    lo = 0, hi = 1e18;
    int largestMin = lo;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        if(check2(mid)){
            largestMin = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    cout << abs(miniMax-largestMin) << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}