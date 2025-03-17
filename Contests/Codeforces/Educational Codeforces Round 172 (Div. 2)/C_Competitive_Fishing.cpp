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
    int k;
    cin >> k;

    string s;
    cin >> s;

    vector<int> arr;
    int sum = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i] == '1') sum++;
        else sum--;

        if(i!=0)
            arr.push_back(sum);
    }

    sort(arr.rbegin(),arr.rend());

    int ans = 0;
    sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum>=k){
            cout << i+2 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int32_t main(){
    
    init();
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();


    return 0;
}