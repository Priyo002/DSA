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
    int n,q;
    cin >> n >> q;

    string s;
    cin >> s;

    while(q--){
        string query;
        cin >> query;
        if(query == "pop_back" && s.size()){
            s.pop_back();
        }  
        else if(query == "front" && s.size()){
            cout << s[0] << endl;
        }
        else if(query == "back" && s.size()){
            cout << s.back() << endl;
        }
        else if(query == "sort"){
            int lq,rq;
            cin >> lq >> rq;
            int l = min(lq,rq), r = max(lq,rq);
            l--, r--;
            if(r<s.size())
                sort(s.begin() + l, s.begin() + r + 1);
        }
        else if(query == "reverse"){
            int lq,rq;
            cin >> lq >> rq;
            int l = min(lq,rq), r = max(lq,rq);
            l--, r--;
            if(r<s.size())
                reverse(s.begin() + l,s.begin() + r + 1);
        }
        else if(query == "print"){
            int pos;
            cin >> pos;
            pos--;
            if(pos<s.size())
                cout << s[pos] << endl;
        }
        else if(query == "substr"){
            int lq,rq;
            cin >> lq >> rq;
            int l = min(lq,rq), r = max(lq,rq);
            l--, r--;
            if(r<s.size())
                cout << s.substr(l,r-l+1) <<endl;
        }
        else if(query == "push_back"){
            char x;
            cin >> x;
            s.push_back(x);
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