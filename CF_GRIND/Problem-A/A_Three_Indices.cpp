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
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    vector<int> prefMin(n,-1), suffMin(n,n);

    int mn = 0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[mn]){
            prefMin[i] = mn;
        }
        else{
            mn = i;
        }
    }
    mn = n-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]>arr[mn]){
            suffMin[i] = mn;
        }
        else{
            mn = i;
        }
    }

    for(int i=1;i<n-1;i++){
        if(prefMin[i]!=-1 && suffMin[i]!=n){
            cout << "YES" << endl;
            cout << prefMin[i]+1 << " " << i+1 << " " << suffMin[i]+1 << endl;
            return;
        }
    }
    cout << "NO" << endl;
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