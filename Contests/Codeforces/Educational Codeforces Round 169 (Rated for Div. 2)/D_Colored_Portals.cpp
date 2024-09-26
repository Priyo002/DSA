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
    int n,q;
    cin >> n >> q;

    unordered_map<string,int> pp;
    pp["BG"] = 1;
    pp["RY"] = 2;
    pp["BR"] = 3;
    pp["GY"] = 4;
    pp["BY"] = 5;
    pp["GR"] = 6;

    vector<string> arr(n);
    vector<vector<int>> mp(7,vector<int>());

    for(int i=0;i<n;i++){
        cin >> arr[i];
        mp[pp[arr[i]]].push_back(i);
    }
    for(int i=1;i<7;i++){
        sort(mp[i].begin(),mp[i].end());
    }
    // BG, BR, BY, GR, GY, or RY;
    unordered_map<string,string> mpp;
    mpp["BG"] = "RY";
    mpp["RY"] = "BG";
    mpp["BR"] = "GY";
    mpp["GY"] = "BR";
    mpp["BY"] = "GR";
    mpp["GR"] = "BY";

    vector<string> temp = {"BG","BR","BY","GR","GY","RY"};
    
    while(q--){
        int u,v;
        cin >> u >> v;
        u--,v--;

        string st = arr[u], en = arr[v];
        if(st[0]==en[0] || st[0]==en[1] || st[1]==en[0] || st[1]==en[1]){
            cout << abs(u-v) << endl;
        }
        else{
            int ans = 1e18;
            string str = mpp[st];
            int l = min(u,v), r = max(u,v);

            for(auto &s : temp){
                if(s==str || s==st) continue;
                if(mp[pp[s]].size()==0) continue;

                vector<int> &temp = mp[pp[s]];

                auto it = upper_bound(temp.begin(),temp.end(),l);

                if(it!=temp.end() && (*it)<=r){
                    ans = r-l;
                    break;
                }
                if(it!=temp.begin()){
                    it--;
                    int idx = *it;
                    ans = min(ans,abs(idx-l) + abs(idx-r));
                }

                auto it1 = upper_bound(temp.begin(),temp.end(),r);
                if(it1!=temp.end()){
                    int idx = *it1;
                    ans = min(ans,abs(idx-l) + abs(idx-r));
                }
            }
           
            if(ans==1e18) ans = -1;
            cout << ans << endl;
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