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

    int x = 0, y = 0;
    for(auto ch : s){
        if(ch=='N') y++;
        else if(ch=='S') y--;
        else if(ch=='W') x--;
        else if(ch=='E') x++;
    }

    if(abs(x)%2==1 || abs(y)%2==1){
        cout << "NO" << endl;
        return;
    }
    if(n==2 && !(s=="NN" || s=="EE" || s=="WW" || s=="SS")){
        cout << "NO" << endl;
        return;
    }

    string ans = "";
    char arr[2] = {'R','H'};
    int N = 0, S = 0, W = 1, E = 1;
    for(auto ch : s){
        if(ch=='N'){
            ans += arr[N];
            N ^= 1;
        }
        if(ch=='S'){
            ans += arr[S];
            S ^= 1;
        }
        if(ch=='E'){
            ans += arr[E];
            E ^= 1;
        }
        if(ch=='W'){
            ans += arr[W];
            W ^= 1;
        }
    }
    cout << ans << endl;
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