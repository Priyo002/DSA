#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 998244353;
const long long INF = 1e18;

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

void solve() {
	ll n, extras = 0, min_ops = 0, factorial = 1, res = 1;
	string s;
	cin >> s;
	vector < ll > v;
	n = (ll)s.size();
	for (ll i = 0 ; i < (n - 1) ; i++) {
		if (s[i] == s[i + 1]) {
			extras++;
		}
		else {
			min_ops += extras;
			extras++;
			res = (res % mod * extras % mod) % mod;
			extras = 0;
		}
	}
	if (extras != 0) {
		min_ops += extras;
		extras++;
		res = (res % mod * extras % mod) % mod;
	}
	for (ll i = 1; i <= min_ops; i++) {
		factorial = ((factorial % mod) * (i % mod)) % mod;
	}
	res = ( (res % mod) * (factorial % mod) ) % mod;
	cout << min_ops << " " << res << endl;


}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}