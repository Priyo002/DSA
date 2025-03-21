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

    vector<vector<int>> arr;

    for(int i=0;i<m;i++){
        int n;
        cin >> n;
        vector<int> temp(n);
        for(int j=0;j<n;j++){
            cin >> temp[j];
        }
        arr.push_back(temp);
    }
    set<int> st;
    vector<int> ans;
    for(int i=m-1;i>=0;i--){
        bool flag = false;
        for(auto x : arr[i]){
            if(st.find(x)==st.end()){
                if(!flag) ans.push_back(x);
                flag = true;
            }
            st.insert(x);
        }
        if(!flag){
            cout << -1 << endl;
            return;
        }
    }

    reverse(ans.begin(),ans.end());
    for(auto x : ans){
        cout << x << " ";
    }
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