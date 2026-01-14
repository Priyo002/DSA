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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> head(n), body(m);
    for(int i=0;i<n;i++){
        cin >> head[i];
    }
    for(int i=0;i<m;i++){
        cin >> body[i];
    }

    sort(head.begin(), head.end());
    sort(body.begin(), body.end());

    int i = 0, j = 0;
    int cnt = 0;
    while(i<n && j<m){
        if(head[i]<=body[j]){
            i++, j++;
            cnt++;
        }
        else{
            j++;
        }
    }
    cout << (cnt>=k ? "Yes" : "No");
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}