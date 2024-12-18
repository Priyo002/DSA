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

int n;
string s;

int f(){
    int cost = 0;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(s[i]=='(') st.push(i);
        else{
            if(st.size()==0) return 1e9;
            cost += (i-st.top());
            st.pop();
        }
    }
    if(st.size()) return 1e9;
    return cost;
}

void solve(){

    cin >> n;
    cin >> s;

    int open = n/2, close = n/2;
    for(auto ch : s){
        open -= (ch=='(');
        close -= (ch==')');
    }

    for(int i=0;i<n;i++){
        if(i&1) continue;
        if(i && s[i-1]=='(' && close-1>=0){
            s[i] = ')';
            close--;
        }
        else s[i] = '(';
    }

    cout << f() << endl;
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
