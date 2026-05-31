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

bool isPrime(int N){
    for(int i=2;i*i<=N;i++){
        if(N%i == 0){
            cout << i << endl;
            return false;
        }
    }
    return true;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n), p(k);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<k;i++){
        cin >> p[i];
        p[i]--;
    }

    vector<int> b(n);
    for(int i=0;i<n;i++){
        b[i] = (arr[i]!=arr[p[0]]);
    }

    vector<int> pref(n + 1, 0);
    for(int i=0;i<=n;i++){
        pref[i] = b[i];
        if(i) pref[i] ^= b[i-1];
    }
    pref[n] = b[n-1];

    vector<int> c(k + 1, 0);

    int currIdx = 0;
    for(int i=0;i<=n;i++){
        if(currIdx < k && p[currIdx] < i){
            currIdx++;
        }
        c[currIdx] += pref[i];
    }

    int total = 0;
    int mx = 0;
    
    for(int i=0;i<=k;i++){
        total += c[i];
        mx = max(mx, c[i]);
    }

    cout << max(mx, total/2) << endl;
}

int32_t main(){
    init();
    
    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    return 0;
}