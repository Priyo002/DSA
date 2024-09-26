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
}

void solve(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> arr(n,vector<int>(m));

    int cnt = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = cnt;
            cnt++;
        }
    }

    bool flag = false;
    for(int i=2;i*i<=m;i++){
        if(m%i==0){
            flag = true;
            break;
        }
    }
    if(!flag){
        vector<vector<int>> ans(n);
        int idx = 0;
        for(int st=1;st<n;st+=2){
            ans[st] = arr[idx];
            idx++;
        }
        for(int st=0;st<n;st+=2){
            ans[st] = arr[idx];
            idx++;
        }
        arr = ans;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}