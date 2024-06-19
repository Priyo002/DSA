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

vector<vector<int>> arr,temp;

void solve(){
    int n,k;
    cin >> n >> k;

    arr.clear();
    temp.clear();

    arr.resize(n,vector<int>(n));
    temp.resize(n,vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            temp[i][j] = arr[i][j];
        }
        reverse(temp[i].begin(),temp[i].end());
    }

    for(int i=0;i<n/2;i++){
        swap(temp[i],temp[n-1-i]);
    }

    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(temp[i][j]!=arr[i][j]){
                cnt++;
            }
        }
    }

    cnt /= 2;
    
    if(cnt>k){
        cout << "NO" << endl;
    }
    else{
        if(n&1){
            cout << "YES" << endl;
            return;
        }
        int rem = k-cnt;
        if(rem&1) cout << "NO";
        else cout << "YES";
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