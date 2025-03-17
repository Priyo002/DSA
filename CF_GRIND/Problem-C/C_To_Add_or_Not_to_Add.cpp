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

int n,k;
vector<int> arr;

pair<bool,int> check(int mid){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(i-mid>=0) sum -= arr[i-mid];
        if(i>=mid-1 && mid*arr[i] - sum <= k) return {true,arr[i]};
    }
    return {false,-1};
}

void solve(){
    cin >> n >> k;

    arr.resize(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    sort(arr.begin(),arr.end());

    int lo = 1, hi = n;
    int freq = 1, ans = arr[0];

    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        auto temp = check(mid);
        if(temp.first){
            freq = mid;
            ans = temp.second;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << freq << " ";
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