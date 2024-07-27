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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));

    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            temp.push_back(arr[i][j]);
        }
    }

    if(n==1 && m==1){
        cout << -1 << endl;
        return;
    }

    if(m==1){
        reverse(temp.begin(),temp.end());
        if(n&1){
            swap(temp[0],temp[n/2]);
        }
        int idx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = temp[idx++];
            }
        }
    }
    else{

        for(int i=0;i<n;i++){
            reverse(arr[i].begin(),arr[i].end());
            if(m&1){
                swap(arr[i][0],arr[i][m/2]);
            }
        }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
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