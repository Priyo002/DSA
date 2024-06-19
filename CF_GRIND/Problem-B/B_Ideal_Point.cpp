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
    int n,k;
    cin >> n >> k;

    vector<pair<int,int>> arr(n), temp;

    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
        if(k>=arr[i].first && k<=arr[i].second){
            temp.push_back(arr[i]);
        }
    }

    bool flag = true;

    for(int num=1;num<=50;num++){
        int cnt = 0;
        if(num==k) continue;
        for(auto x : temp){
            if(num>=x.first && num<=x.second){
                cnt++;
            }
        }
        if(cnt==temp.size()){
            flag = false;
            break;
        }
    }

    if(!flag) cout << "NO" << endl;
    else cout << "YES" << endl;
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