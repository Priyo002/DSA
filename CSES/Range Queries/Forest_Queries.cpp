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
    int n,q;
    cin >> n >> q;

    vector<vector<int>> arr(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        for(int j=1;j<=n;j++){
            if(s[j-1]=='.') arr[i][j] = 0;
            else arr[i][j] = 1;
            arr[i][j] += (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
        }
    }

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    while(q--){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = arr[x2][y2];
        sum -= arr[x1-1][y2];
        sum -= arr[x2][y1-1];
        sum += arr[x1-1][y1-1];
        cout << sum << endl;
    }
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}