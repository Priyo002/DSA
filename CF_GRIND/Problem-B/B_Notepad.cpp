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
    cin >> n ;

    string s;
    cin >> s;

    map<string,vector<int>> mp;

    for(int i=0;i<n-1;i++){
        string str = "";
        str += s[i];
        str += s[i+1];
        mp[str].push_back(i);
    }

    bool flag = false;
    for(auto x : mp){
        if(x.second.size()>1){
            vector<int> temp = x.second;
            for(int i=temp.size()-1;i>=1;i--){
                if(temp[0]+1!=temp[i]){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
    }

    if(flag) cout << "YES";
    else cout << "NO";
    cout << endl;

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