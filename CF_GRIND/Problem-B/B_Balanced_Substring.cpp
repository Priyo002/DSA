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

    string s;
    cin >> s;

    vector<int> cntZero(n,0), cntOne(n,0);

    for(int i=0;i<n;i++){
        if(s[i]=='0')
            cntZero[i] = 1;
        else
            cntOne[i] = 1;
    }

    for(int i=1;i<n;i++){
        cntZero[i] += cntZero[i-1];
        cntOne[i] += cntOne[i-1];
    }

    vector<int> bal(n);

    int ans = 0;

    map<int,int> mp;
    mp[0] = -1;

    for(int i=0;i<n;i++){
        //bal[i] = cntOne[i]-cntZero[i];
        bal[i] = cntZero[i]-cntOne[i];
        if(mp.count(bal[i])){
            ans = max(ans,i-mp[bal[i]]);
        }
        else{
            mp[bal[i]] = i;
        }
    }

    cout << ans;
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