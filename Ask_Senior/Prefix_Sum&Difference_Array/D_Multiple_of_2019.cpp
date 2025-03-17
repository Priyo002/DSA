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
    string s;
    cin >> s;

    vector<int> arr(2019,0);
    arr[0] = 1;
    
    int ans = 0, powerOfTen = 1, currNum = 0;
    for(int i=s.size()-1;i>=0;i--){
        int digit = s[i] - '0';
        currNum = (currNum + (digit * powerOfTen)%2019)%2019;
        ans += arr[currNum];
        arr[currNum]++;
        powerOfTen = (10 * powerOfTen)%2019;
    }
    cout << ans;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}