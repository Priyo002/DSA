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
    int n,m;
    cin >> n >> m;

    string s,t;
    cin >> s >> t;

    if(s[0]!=t[0]){
        cout << "NO" << endl;
        return;
    }

    int i = 0, j = 0;
    while(i<n && j<m){
        if(i+1<n && j+1<m){
            if(s[i+1]!=t[j+1]){
                
            }
            else{
                i++;
                j++;
            }
        }
        else{

        }
    }
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}