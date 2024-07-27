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
    int n;
    cin >> n;

    vector<int> arr(n);
    int cnt = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]!=i+1){
            cnt++;
        }
    }
    if(cnt==0){
        cout << 0 << endl;
        return;
    }
    
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            int j = i;
            int d = 0;
            while(j<n && arr[j]!=j+1){
                d++;
                j++;
            }
            if(d==cnt){
                cout << 1 << endl;
                return;
            }
            i = j - 1;
        }
    }
    cout << 2 << endl;
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