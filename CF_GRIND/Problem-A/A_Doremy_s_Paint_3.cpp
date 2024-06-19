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
    map<int,int> mp;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }

    if(mp.size()==1){
        cout << "Yes" << endl;
    }
    else if(mp.size()==2){
        auto it = mp.begin();
        int cnt1 = it->second;
        ++it;
        int cnt2 = it->second;
        if(cnt2<cnt1) swap(cnt1,cnt2);
        if(n&1){
            if(cnt2==1+cnt1){
                cout << "Yes" ;
            }
            else{
                cout << "No";
            }
            cout << endl;
        }
        else{
            if(cnt1==cnt2) cout << "Yes";
            else cout << "No";
            cout << endl;
        }
    }
    else{
        cout << "No" << endl;
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