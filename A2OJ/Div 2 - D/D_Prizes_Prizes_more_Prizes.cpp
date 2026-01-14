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

    vector<int> arr(n);
    for(int &x : arr){
        cin >> x;
    }

    vector<int> brr(5,0);
    for(int &x : brr){
        cin >> x;
    }

    vector<int> freq(5,0);
    int total = 0;
    for(int &x : arr){
        total += x;
        for(int i=4;i>=0;i--){
            if(brr[i] <= total){
                int cnt = total/brr[i];
                freq[i] += cnt;
                total -= (cnt*brr[i]);
            }
        }
    }

    for(int &x : freq){
        cout << x << " ";
    }
    cout << endl;
    cout << total;
}

int32_t main(){
    
    init();
    int _t = 1;
    //cin >> _t;
    while(_t--)
        solve();


    return 0;
}