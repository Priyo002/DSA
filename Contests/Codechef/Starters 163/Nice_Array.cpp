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
    long double n,k;
    cin >> n >> k;

    vector<long double> arr(n);
    long double sum = 0;
    for(auto &x : arr){
        cin >> x;
        sum += ceil(x/k);
    }

    if(sum == 0){
        cout << "YES" << endl;
        return;
    }
    if(k == 1){
        cout << "NO" << endl;
        return;
    }
    if(sum > 0){
        for(auto &x : arr){
            int t1 = floor(x/k);
            int t2 = ceil(x/k);
            if(t1 != t2 && sum>0){
                sum--;
            }
        }
    }

    if(sum == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
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