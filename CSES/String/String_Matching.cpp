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
    string s,t;
    cin >> s >> t;

    if(s==t){
        cout << 1;
        return;
    }

    string str = t + "#" + s;

    int n = str.size();
    vector<int> kmp(n+1);
    kmp[0] = -1;
    int i = 0, j = -1;
    while(i<n){
        while(j!=-1 && str[i]!=str[j]){
            j = kmp[j];
        }
        i++;
        j++;
        kmp[i] = j;
    }

    int ans = 0;
    for(int i=(int)t.size()+1;i<n;i++){
        if(kmp[i+1]==(int)t.size()) ans++;
    }
    cout << ans ;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}