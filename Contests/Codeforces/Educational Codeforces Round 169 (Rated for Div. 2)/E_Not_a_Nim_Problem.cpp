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
vector<int> arr;


int f(int i){
    if(i==0) return 0;
    int ans = 0;
    for(int j=1;j<=i;j++){
        if(__gcd(i,j)==1 && f(i-j)==0){
            ans = 1;
        }
    }
    return ans;
}

void solve(){
    //cin >> n;

    // arr.clear();
    // arr.resize(n);
    
    // for(int i=0;i<n;i++) cin >> arr[i];


    for(int i=1;i<=10;i++){
        cout << i << "-> " << f(i) << endl;
    }

}

int32_t main(){
    
    init();

    //sieve(1001000);

    int _t = 1;
   // cin >> _t;
    while(_t--)
        solve();


    return 0;
}