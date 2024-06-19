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

    vector<string> arr;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        arr.push_back(s);
    }

    int ans = 1e9;
    for(int i=1;i<(1LL<<n);i++){
        vector<string> temp;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                temp.push_back(arr[j]);
            }
        }
        set<int> st;
        for(auto x : temp){
            for(int k=0;k<m;k++){
                if(x[k]=='o'){
                    st.insert(k);
                }
            }
        }
        bool flag = true;
        for(int k=0;k<m;k++){
            if(st.count(k)==0){
                flag = false;
                break;
            }
        }
        if(flag){
            ans = min(ans,(int)temp.size());
        }
    }
    cout << ans << endl;
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