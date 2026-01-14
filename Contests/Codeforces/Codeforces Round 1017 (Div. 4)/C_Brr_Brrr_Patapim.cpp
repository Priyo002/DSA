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
    int n;
    cin >> n;

    vector<int> arr(2*n + 1,0);

    vector<vector<int>> brr(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> brr[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            arr[i+j] = brr[i][j];
        }
    }

    set<int> st(arr.begin(),arr.end());
    vector<int> ans;
    for(int i=1;i<=2*n;i++){
        if(!st.count(i)){
            ans.push_back(i);
        }
    }

    for(int i=1;i<=2*n;i++){
        if(arr[i] == 0){
            arr[i] = ans.back();
            ans.pop_back();
        }
        cout << arr[i] << " ";
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