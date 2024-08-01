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
    int m;
    cin >> m;
    
    vector<string> arr(2);
    cin >> arr[0] >> arr[1];

    bool flag = false;
    for(int i=0;i<2;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.') flag = true;
        }
    }

    if(!flag){
        cout << 0 << endl;
        return;
    }

    vector<int> pref(m,0), suff(m,0);

    for(int j=0;j<m;j++){
        if(arr[0][j]=='.') pref[j]++;
        if(arr[1][j]=='.') pref[j]++;
        if(j) pref[j] += pref[j-1];
    }

    for(int j=m-1;j>=0;j--){
        if(arr[0][j]=='.') suff[j]++;
        if(arr[1][j]=='.') suff[j]++;
        if(j+1<m) suff[j] += suff[j+1];
    }

    // for(int i=0;i<m;i++){
    //     cout << pref[i] << " ";
    // }
    // cout << endl;
    // for(int i=0;i<m;i++){
    //     cout << suff[i] << " ";
    // }
    // cout << endl;

    int ans = 0;
    for(int j=1;j<m-1;j++){
        if(arr[0][j]=='.' && arr[1][j]=='.'){
            if(pref[j-1]>0 && suff[j+1]>0 && arr[1][j-1]=='x' && arr[1][j+1]=='x'){
                ans++;
            }
            if(pref[j-1]>0 && suff[j+1]>0 && arr[0][j-1]=='x' && arr[0][j+1]=='x'){
                ans++;
            }
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