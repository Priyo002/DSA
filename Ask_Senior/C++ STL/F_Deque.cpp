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
    int q;
    cin >> q;
    deque<int> dq;
    while(q--) {
        string cmd;
        cin >> cmd;
        if(cmd == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        } 
        else if(cmd == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        } 
        else if(cmd == "pop_front") {
            dq.pop_front();
        } 
        else if(cmd == "pop_back") {
            dq.pop_back();
        } 
        else if(cmd == "front") {
            cout << dq.front() << endl;
        } 
        else if(cmd == "back") {
            cout << dq.back() << endl;
        } 
        else if(cmd == "print") {
            int x;
            cin >> x;
            cout << dq[x - 1] << endl;
        }
    }
}

int32_t main(){
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();
    return 0;
}
