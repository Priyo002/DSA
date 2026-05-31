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
    int n;
    cin >> n;

    vector<string> arr(n);
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(s == "for"){
            int val;
            cin >> val;
            s += to_string(val);
        }
        arr[i] = s;
    }

    stack<int> st;
    st.push(1);
    int x = 0;
    for(auto &s : arr){
        if(s == "add"){
            x += st.top();
        }
        else if(s == "end"){
            st.pop();
        }
        else if(s[0] == 'f'){
            int newProd = st.top() * stoi(s.substr(3));
            if(newProd > (1LL<<32) - 1){
                newProd = (1LL<<32);
            }
            st.push(newProd);
        }
    }

    if(x > (1LL<<32) - 1){
        cout << "OVERFLOW!!!";
    }
    else{
        cout << x;
    }
    cout << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}