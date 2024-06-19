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
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

int n,k;
vector<int> arr;

bool check(int steps){
    int j = steps*k;

    if(j>=n) return true;

    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]<=n-j) temp.push_back(arr[i]);
    }

    return is_sorted(temp.begin(),temp.end());
}

void solve(){
    cin >> n >> k;

    arr.resize(n);
    for(int i=0;i<n;i++) cin >> arr[i];


    int lo = 0, hi = n;
    int ans = -1;

    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(check(mid)){
            ans = mid;
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
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}