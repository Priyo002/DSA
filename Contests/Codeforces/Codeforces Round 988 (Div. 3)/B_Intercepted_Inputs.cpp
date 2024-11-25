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
    int k;
    cin >> k;

    vector<int> arr(k);
    for(int &x : arr) cin >> x;

    k -= 2;
    map<int,int> mp;
    for(auto &x : arr) mp[x]++;

    for(int &x : arr){
        if(k%x==0){
            int y = k/x;
            if(y==x){
                if(mp.count(y) && mp[y]>=2){
                    cout << x << " " << y << endl;
                    return;
                }
            }
            else{
                if(mp.count(y)){
                    cout << x << " " << y << endl;
                    return;
                }
            }
        }
    }

}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}