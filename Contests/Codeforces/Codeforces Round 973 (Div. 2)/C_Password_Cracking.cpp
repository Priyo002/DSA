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

bool query(string s){
    cout << "? " << s << endl;
    cout.flush();
    int flag;
    cin >> flag;
    return flag;
}

void solve(){
    int n;
    cin >> n;

    string s = "";

    while((int)s.size()<n){
        if(query(s+"0")){
            s += "0";
            continue;
        }
        if(query(s+"1")){
            s += "1";
            continue;
        }
        break;
    }

    while((int)s.size()<n){
        if(query("0" + s)){
            s = "0" + s;
            continue;
        }
        else{
            s = "1" + s;
            continue;
        }
        break;
    }

    cout << "! " << s << endl;
    cout.flush();
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}