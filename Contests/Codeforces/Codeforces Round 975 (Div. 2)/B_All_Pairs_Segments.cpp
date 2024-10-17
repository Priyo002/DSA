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

    vector<int> points(n);
    for(int i=0;i<n;i++){
        cin >> points[i];
    }

    
    
    map<int,int> ans;

    for(int i=0;i<n;i++){
        int cnt = i*(n-i) + (n-i-1);
        ans[cnt]++;
        if(i>0){
            if(points[i]-points[i-1]-1>0){
                cnt = i*(n-i);
                ans[cnt] += (points[i]-points[i-1]-1);
            }
        }
    }
    
    while(q--){
        int x;
        cin >> x;

        cout << ans[x] << " ";
    }
    cout << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}