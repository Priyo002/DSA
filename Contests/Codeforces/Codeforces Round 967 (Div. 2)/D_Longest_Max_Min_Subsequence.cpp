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

map<int,int> mp;

bool check(int val){
    if(mp.count(val)==0) return true;
    return mp[val]!=1;
}

void solve(){
    int n;
    cin >> n;

    
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }

    int m = mp.size();
    vector<int> ans;
    int mx = -INF, mn = INF;
    set<int> taken;
    for(int i=0;i<n;i++){

        if(taken.count(arr[i])) continue;

        if(ans.size()%2==0){//max
            int m = mp.size();
            mp[arr[i]]--;
            if(mp[arr[i]]==0){
                mp.erase(arr[i]);
            }
            if(mp.size()!=m){
                if(mx!=-INF){
                    // cout << i << endl;
                    // cout << mx << " h1" << endl;
                    ans.push_back(mx);
                    taken.insert(mx);
                    if(mp.count(mx)) mp.erase(mx);
                    mx = -INF;
                    if(taken.count(arr[i])==0)
                        mn = arr[i];
                    else mn = INF;
                }
                else{
                    //cout << arr[i] << " h2" << endl;
                    ans.push_back(arr[i]);
                    taken.insert(arr[i]);
                    if(mp.count(arr[i])) mp.erase(arr[i]);
                    mx = -INF;
                    mn = INF;
                }
            }
            else{
                mx = max(mx,arr[i]);
            }
        }
        else{//min
            int m = mp.size();
            mp[arr[i]]--;
            if(mp[arr[i]]==0){
                mp.erase(arr[i]);
            }
            if(mp.size()!=m){
                if(mn!=INF){
                    // cout << i << endl;
                    // cout << mn << " h3" << endl;
                    ans.push_back(mn);
                    taken.insert(mn);
                    if(mp.count(mn)) mp.erase(mn);
                    mn = INF;
                    if(taken.count(arr[i])==0)
                        mx = arr[i];
                    else
                        mx = -INF;
                }
                else{ 
                    //cout << arr[i] << " h4" << endl;
                    ans.push_back(arr[i]);
                    taken.insert(arr[i]);
                    if(mp.count(arr[i])) mp.erase(arr[i]);
                    mn = INF;
                    mx = -INF;
                }
            }
            else mn = min(mn,arr[i]);
        }
    }
    if(ans.size()%2==0){
        if(mx!=-INF) ans.push_back(mx);
    }
    else{
        if(mn!=INF) ans.push_back(mn);
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
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