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

void solve(){
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> arr;
    for(int i=1;i<=n;i++) arr.push_back(i);


    vector<int> a,b;
    for(int i=1;i<=m;i++){
        a.push_back(i);
    }

    for(int i=n;i>=k;i--){
        b.push_back(i);
    }

    vector<int> ans;
    for(auto x : b){
        ans.push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(i<k && i>m) ans.push_back(i);
    }

    for(auto x : a) ans.push_back(x);

    for(auto x : ans) cout << x << " ";
    cout << endl;

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