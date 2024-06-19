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

    vector<int> ans;
    int extra = n%4;

    if(extra==1){
        ans.push_back(0);
    }
    else if(extra==2){
        ans.push_back(1);
        ans.push_back((1LL<<30)+1);
    }
    else if(extra==3){
        ans.push_back(1);
        ans.push_back(2);
        ans.push_back(3);
    }

    if(n<4){
        for(auto x : ans){
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    int st = 6;
    int en = st + (4*(n/4));
    for(int i = st;i<en;i++){
        ans.push_back(i);
    }
    
    sort(ans.begin(),ans.end());

    int bit = -1;
    for(int i=0;i<62;i++){
        if((ans[1]>>i)&1){
            bit = i;
            break;
        }
    }
    vector<int> t1,t2;
    for(auto x : ans){
        if((x>>bit)&1){
            t1.push_back(x);
        }
        else{
            t2.push_back(x);
        }
    }
    
    
    int k = ans.size();

    if(t1.size()>=t2.size()){
        for(int i=0, j = 0;i<t1.size() && j<k;i++, j+= 2){
            ans[j] = t1[i]; 
        }
        for(int i=0, j = 1;i<t2.size() && j<k;i++, j+= 2){
            ans[j] = t2[i]; 
        }
    }
    else{
        for(int i=0, j = 0;i<t2.size() && j<k;i++, j+= 2){
            ans[j] = t2[i]; 
        }
        for(int i=0, j = 1;i<t1.size() && j<k;i++, j+= 2){
            ans[j] = t1[i]; 
        }
    }
    
    if(extra==2){
        if(ans[0]%2!=0){
            ans[1] = (ans[1]|(1LL<<30));
        }
        else{
            ans[0] = (ans[0]|(1LL<<30));
        }
    }
    
    for(auto x : ans){
        cout << x << " ";
    }
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