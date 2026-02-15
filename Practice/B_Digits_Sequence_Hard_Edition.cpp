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

int k;

int getNoOfDigitsTill(int val){
    int noOfDigits = to_string(val).size();
    int cnt = 0, curr = 9, temp = 1;
    for(int i=1;i<=noOfDigits-1;i++){
        cnt += (i*curr);
        curr *= 10;
        temp *= 10;
    }
    cnt += (noOfDigits*(val - temp + 1));
    return cnt;
}

bool check(int mid){
    return (getNoOfDigitsTill(mid) >= k);
}

void solve(){
    cin >> k;

    int lo = 1, hi = k;
    int num = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)){
            num = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }   

    int idx = k - getNoOfDigitsTill(num - 1);
    cout << to_string(num)[idx - 1] << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}