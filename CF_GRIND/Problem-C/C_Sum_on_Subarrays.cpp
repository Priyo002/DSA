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

vector<int> f(int n, int k) {
    if (n == 0) {
        return {};
    }
    if(k<n){
        vector<int> a(n, -1);
        if (k > 0) {
            a[k - 1] = 300;
        }
        a[k] = -800;
        return a;
    } 
    else{
        vector<int> a = f(n - 1, k - n);
        a.push_back(1000);
        return a;
    }   
}

void solve(){
    int n,k;
    cin >> n >> k;

    vector<int> arr = f(n,k);

    for(int i=0;i<n;i++) cout << arr[i] << " ";
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