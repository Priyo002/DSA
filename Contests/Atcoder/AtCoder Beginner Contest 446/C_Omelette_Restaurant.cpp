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
    int n, d;
    cin >> n >> d;

    vector<int> arr(n), brr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        cin >> brr[i];
    }

    queue<pair<int,int>> qu;
    for(int i=0;i<n;i++){
        int cnt = brr[i];
        qu.push({arr[i], i});
        while(qu.size() && cnt > 0){
            auto curr = qu.front();
            if(curr.second < i-d){
                qu.pop();
            }
            else{
                if(cnt >= curr.first){
                    cnt -= curr.first;
                    qu.pop();
                }
                else{
                    qu.front().first -= cnt;
                    cnt = 0;
                }
            }
        }
    }

    int cnt = 0;
    while(qu.size()){
        if(qu.front().second <= n-1-d){
            qu.pop();
        }
        else{
            cnt += qu.front().first;
            qu.pop();
        }
    }
    cout << cnt << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    return 0;
}