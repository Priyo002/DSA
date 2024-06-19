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

vector<vector<int>> a,b;

string getS(vector<int>& arr){
    sort(arr.begin(),arr.end());
    string s = "";
    for(auto x : arr){
        s += to_string(x);
        s += " ";
    }
    return s;
}

void solve(){
    int n,m;
    cin >> n >> m;

    a.clear(), b.clear();
    a.resize(n,vector<int>(m));
    b.resize(n,vector<int>(m));

    map<string,int> mp;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> b[i][j];
        }
    }

    for(int j=0;j<m;j++){
        vector<int> arr;
        for(int i=0;i<n;i++){
            arr.push_back(a[i][j]);
        }
        mp[getS(arr)] = j;
    }
    bool f1 = true, f2 = true;

    for(int j=0;j<m;j++){
        vector<int> arr;
        for(int i=0;i<n;i++){
            arr.push_back(b[i][j]);
        }
        string s = getS(arr);
        if(mp.find(s)==mp.end()){
            cout << "NO" << endl;
            return;
        }
        else mp.erase(s);
    }

    mp.clear();

    for(int i=0;i<n;i++){
        string s = getS(a[i]);
        mp[s] = i;
    }
    
    for(int i=0;i<n;i++){
        string s = getS(b[i]);
        if(mp.find(s)==mp.end()){
            cout << "NO" << endl;
            return;
        }
        else mp.erase(s);
    }

    cout << "YES" << endl;
    
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