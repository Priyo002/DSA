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

vector<vector<string>> ans;
int level;

void f(int open,int close,string& curr){
    if(ans[level].size()>=101) return;
    if(open+close==2*level){
        ans[level].push_back(curr);
        return;
    }

    if(open+1<=level){
        curr.push_back('(');
        f(open+1,close,curr);
        curr.pop_back();
        
    }
    if(open>0 && close+1<=open){
        curr.push_back(')');
        f(open,close+1,curr);
        curr.pop_back();
    }
}


void solve(){

    int q;
    cin>>q;

    vector<int> arr(q);

    ans.clear();
    ans.resize(51,vector<string>());

    for(int i=0;i<q;i++) cin >> arr[i];

    //for(auto x : arr) cout << x << " ";

    set<int> st;

    for(auto x : arr){
        if(st.count(x)) continue;
        level = x;
        string curr = "";
        f(0,0,curr);
        st.insert(x);
    }

    map<int,int> mp;

    for(auto x : arr){
        mp[x] = x-1;
    }

    for(auto x : arr){
        vector<string> temp = ans[x];
        for(int i=0;i<x-1;i++){
            cout << temp[i] << endl;
        }
        if(mp[x]<temp.size()){
            cout << temp[mp[x]] << endl;
            mp[x]++;
        }
    }

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