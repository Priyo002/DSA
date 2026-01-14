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
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();

    vector<int> div1, div2;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            div1.push_back(i);
            if(i!=n/i){
                div1.push_back(n/i);
            }
        }
    }

    for(int i=1;i*i<=m;i++){
        if(m%i == 0){
            div2.push_back(i);
            if(i!=m/i){
                div2.push_back(m/i);
            }
        }
    }

    map<string,int> mp;
    for(int &len : div1){
        string s = s1.substr(0,len);
        
        bool flag = true;
        for(int i=len;i<n;i+=len){
            if(s1.substr(i,len) != s){
                flag = false;
                break;
            }
        }
        if(flag){
            mp[s]++;
        }
    }

    for(int &len : div2){
        string s = s2.substr(0,len);
        bool flag = true;
        for(int i=len;i<m;i+=len){
            if(s2.substr(i,len) != s){
                flag = false;
                break;
            }
        }
        if(flag){
            mp[s]++;
        }
    }

    int ans = 0;
    for(auto &x : mp){
        ans += (x.second == 2);
    }
    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();


    return 0;
}