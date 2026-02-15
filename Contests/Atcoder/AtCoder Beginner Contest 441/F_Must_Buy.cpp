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

int n;
vector<pair<int,int>> arr;
map<pair<int,int>, int> freq;
int dp[1001][50001];

int f(int idx,int leftM){
    if(idx == n){
        return 0;
    }

    if(dp[idx][leftM]!=-1) return dp[idx][leftM];

    int ans = f(idx + 1, leftM);
    if(leftM - arr[idx].first >= 0){
        ans = max(ans, arr[idx].second + f(idx+1, leftM - arr[idx].first));
    }

    return dp[idx][leftM] = ans;
}

void print(int idx, int leftM, int val){
    if(idx == n) return;

    if(f(idx+1, leftM) == val){
        print(idx+1, leftM, val);
    }
    else{
        freq[arr[idx]]++;
        print(idx+1, leftM - arr[idx].first, val - arr[idx].second);
    }
}

void solve(){
    int m;
    cin >> n >> m;

    arr.clear();
    arr.resize(n);

    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }

    memset(dp, -1, sizeof(dp));
    int val = f(0, m);
    print(0, m, val);

    for(auto &p : arr){
        if(freq.count(p)){
            if(freq[p] == 1){
                cout << "A";
            }
            else{
                cout << "B";
            }
        }
        else {
            cout << "C";
        }
    }

}

int32_t main(){
    
    init();
    int _t = 1;
    // cin >> _t;
    while(_t--)
        solve();

    return 0;
}