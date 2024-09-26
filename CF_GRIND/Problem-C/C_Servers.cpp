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

using pp = pair<int,int>;

void solve(){
    int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    iota(arr.begin(),arr.end(),1);
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    for(int i=1;i<=n;i++){
        pq.push({1,i});
    }
    while(q--){
        int t,k,d;
        cin >> t >> k >> d;

        vector<pp> temp;
        while(pq.size()){
            auto curr = pq.top();
            if(curr.first>t) break;
            pq.pop();
            temp.push_back({curr.second,curr.first});
        }
        // for(auto x : temp){
        //     cout << x.second << "," << x.first << "  ";

        // }
        // cout << endl;
        if(temp.size()>=k){
            sort(temp.begin(),temp.end());
            int sum = 0;
            for(int i=0;i<temp.size();i++){
                if(i<k){
                    sum += temp[i].first;
                    pq.push({t+d,temp[i].first});
                }
                else{
                    pq.push({temp[i].second,temp[i].first});
                }
            }
            cout << sum ;
        }
        else{
            cout << -1;
            for(auto x : temp){
                pq.push({x.second,x.first});
            }
        }
        cout << endl;
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}