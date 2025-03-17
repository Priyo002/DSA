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
    int n,m,k;
    cin >> n >> m >> k;

    vector<pair<int,int>> arr;

    for(int i=1;i<=n;i++){
        if(i&1){
            for(int j=1;j<=m;j++){
                arr.push_back({i,j});
            }
        }
        else{
            for(int j=m;j>=1;j--){
                arr.push_back({i,j});
            }
        }
    }   

    int j = 0;
    for(int i=0;i<k-1;i++){
        cout << 2 << " ";
        for(int l=0;l<2;l++){
            cout << arr[j].first << " " << arr[j].second << " ";
            j++;
        }
        cout << endl;
    }
    cout << arr.size() - j << " ";
    while(j<arr.size()){
        cout << arr[j].first << " " << arr[j].second << " ";
        j++;
    }
    cout << endl;

}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}