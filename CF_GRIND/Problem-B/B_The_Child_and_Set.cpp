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
    int sum,limit;
    cin >> sum >> limit;

    map<int,vector<int>> mp;
    map<int,int,greater<int>> freq;

    for(int i=1;i<=limit;i++){
        for(int j=0;j<=30;j++){
            if((i>>j)&1){
                mp[(1<<j)].push_back(i);
                freq[(1<<j)]++;
                break;
            }
        }
    }
    
    map<int,int> store;

    for(auto x : freq){
        int num = x.first, cnt = x.second;
        if(sum<num) continue;

        int need = sum/num;
        if(need<=cnt){
            sum -= (need*num);
            store[num] = need;
        }
        else{
            sum -= (cnt*num);
            store[num] = cnt;
        }
    }
    if(sum!=0){
        cout << -1 << endl;
        return;
    }
    vector<int> ans;

    for(auto x : store){
        vector<int> temp = mp[x.first];
        
        for(int i=0;i<x.second;i++){
            ans.push_back(temp[i]);
        }
    }
    cout << ans.size() << endl;
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
    //cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}