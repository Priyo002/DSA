#include<bits/stdc++.h>
using namespace std;
using pp = pair<int,int>;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<pp, null_type,less<pp>, rb_tree_tag,tree_order_statistics_node_update>

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
vector<pair<int,int>> arr;
vector<int> a,b,tot;

void solve(){
    cin >> n >> k;

    arr.clear(), a.clear(), b.clear();
    arr.resize(n);

    for(int i=0;i<n;i++) cin >> arr[i].first;
    for(int i=0;i<n;i++) cin >> arr[i].second;

    sort(arr.begin(),arr.end());

    for(auto x : arr){
        if(x.second) a.push_back(x.first);
        else b.push_back(x.first);
        tot.push_back(x.first);
    }

    for(auto x : arr){
        if(x.second){

        }
        else{
            int lo = 0, hi = 1e18;
            int ans = -1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(check(mid,x.first)){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
        }
    }
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