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

    for(int i=0;i<n;i++) cin >> arr[i];

    map<string,map<int,int>> mp;

    string s1;
    for(int i=0;i<n-2;i++){
        s1 = "o" + to_string(arr[i]) + "tw" + to_string(arr[i+1]);
        mp[s1][arr[i+2]]++;
        s1 = "tw" + to_string(arr[i+1]) + "th" + to_string(arr[i+2]);
        mp[s1][arr[i]]++;
        s1 = "o" + to_string(arr[i]) + "th" + to_string(arr[i+2]);
        mp[s1][arr[i+1]]++;
    }

    int ans = 0;

    for(auto x : mp){
        map<int,int> temp = x.second;
        int sum = 0;
        for(auto y : temp){
            sum += y.second;
        }
        for(auto y : temp){
            ans += ((sum-y.second)*(y.second));
        }
    }


    cout << ans/2 << endl;
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