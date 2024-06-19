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

    vector<int> a(n),b(n);

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int m;
    cin >> m;

    vector<int> d(m);
    for(int i=0;i<m;i++){
        cin >> d[i];
    }

    map<int,int> mp1,mp2;

    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            mp2[b[i]]++;
        }
        mp1[b[i]]++;
    }

    int cnt = 0;
    for(auto x : d){
        if(mp2.find(x)!=mp2.end()){
            cnt = 0;
            mp2[x]--;
            if(mp2[x]==0) mp2.erase(x);
        }
        if(mp1.find(x)!=mp1.end()){
            cnt = 0;
        }
        else{
            cnt++;
        }
    }

    if(cnt>0 || mp2.size()!=0){
        cout << "NO";
    }
    else cout << "YES";
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