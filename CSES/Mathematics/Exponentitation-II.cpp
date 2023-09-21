#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
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

int powr(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = ((res % mod) * (a % mod)) % mod;
		a = ((a % mod) * (a % mod)) % mod;
		b = (b >> 1);
	}
	return res;

}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int x = powr(b, c) % mod;
	cout << powr(a, x) % mod << endl;
}

int32_t main() {

	init();
	int t;
	cin >> t;
	while (t--)
		solve();

}