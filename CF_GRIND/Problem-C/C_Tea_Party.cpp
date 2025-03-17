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
    int n,w;
    cin >> n >> w;

    int total = 0;
    vector<int> ans, arr;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
        total += ((x+2-1)/2);
        ans.push_back(((x+2-1)/2));
    }
    if(total>w){
        cout << -1 << endl;
        return;
    }
    else{
        vector<vector<int>> temp(n);
        for(int i=0;i<n;i++){
            temp[i] = {arr[i],ans[i],i};
        }
        sort(temp.begin(),temp.end());
        int mx = temp[0][1];
        ans[temp[0][2]] = temp[0][1];
        for(int i=1;i<n;i++){
            if(temp[i][1] < mx){
                total += (mx - temp[i][1]);
                temp[i][1] = mx;
            }
            if(temp[i][1] > temp[i][0]){
                cout << -1 << endl;
                return;
            }
            ans[temp[i][2]] = temp[i][1];
            mx = max(mx, temp[i][1]);
        }
        if(total > w){
            cout << -1 << endl;
            return;
        }

        int left = w - total;

        int diff = temp[n-1][0] - temp[n-1][1];
        temp[n-1][1] += min({left,diff});
        left -= min({left,diff});
        mx = temp[n-1][1];
        ans[temp[n-1][2]] = temp[n-1][1];

        for(int i=n-2;i>=0;i--){
            diff = temp[i][0] - temp[i][1];
            int k = min({left,diff,mx - temp[i][1]});
            temp[i][1] += k;
            left -= k;            
            mx = min(mx, temp[i][1]);
            ans[temp[i][2]] = temp[i][1];
        }
        
        if(left > 0) cout << -1;
        else{
            for(auto &x : ans){
                cout << x << " ";
            }
        }
        cout << endl;
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