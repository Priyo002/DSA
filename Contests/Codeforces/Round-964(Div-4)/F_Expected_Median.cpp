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
    
    //#ifndef ONLINE_JUDGE
        //freopen("inputf.in","r",stdin);
        //freopen("outputf.in","w",stdout);
    //#endif
}

int fact[400100];
void precompute() { //mod must be prime
	fact[0] = 1;
	for (int i = 1; i <= 400000; i++) {
		fact[i] = ((i % mod) * (fact[i - 1] % mod)) % mod;
	}
}

int powr(int a, int b, int mod=1e9+7) {
	int res = 1;
	while (b) {
		if (b & 1) res = (((res % mod) * (a % mod)) % mod);
		a = ((a % mod) * (a % mod)) % mod;
		b = (b >> 1);
	}
	return (res % mod);
}
int modInverse(int a, int b = 1e9 + 7) {
	return powr(a, b - 2, mod);
}

int ncr(int n, int r, int mod) {
	if (r < 0 || r > n) return 0;

	int ans = fact[n];
	ans = ((ans % mod) * (modInverse(fact[r], mod) % mod)) % mod;
	ans = ((ans % mod) * (modInverse(fact[n - r], mod) % mod)) % mod;
	ans = (ans % mod + mod) % mod;

	return ans;
}

void solve(){
    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> pref(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i]==1) pref[i] = 1;
        if(i) pref[i] += pref[i-1];
    }   

    int m = (k-1)/2;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) continue;

        int t = i;
        int one = pref[n-1];
        one -= pref[i];

        int val = ((ncr(n-one-1,m,mod)*ncr(one,m,mod))%mod);
        ans = ((ans%mod)+ val)%mod;
    }
    
    cout << ans << endl;
}

int32_t main(){
    
    init();
    //clock_t time_req;
    //time_req = clock();

    precompute();

    int _t = 1;
    cin >> _t;
    while(_t--)
        solve();

    //time_req = clock() - time_req;
    //cout << endl << "Time Taken is ";
    //cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}