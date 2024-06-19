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
    int n, k;
    cin >> n >> k;

    vector<int> arr;

    for(int i=1;i<=n;i++){
        arr.push_back(i);
    }

    int total = 0LL;
    for (int i=1;i<=n;i++) {
        total += abs(i-(n-i+1));
    }

    if((k&1) || (total-k<0)){
        cout << "No" << endl;
    } 
    else{
        cout << "Yes" << endl;
        int idx = 0LL;
        int m = n;
        while(k>2*(m - 1)){
            swap(arr[idx],arr[n-idx-1]);
            k-=2*(m - 1);
            m-=2;
            idx++;
        }
        k = (k>>1);
        swap(arr[idx], arr[idx + k]);

        int l = arr.size();
        for(int i=0;i<l;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
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