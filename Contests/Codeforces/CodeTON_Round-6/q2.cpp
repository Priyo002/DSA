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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	int xorr1 = 0;
	for (auto x : a) {
		xorr1 ^= x;
	}
	int orr = *max_element(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		a[i] |= orr;
	}
	int xorr2 = 0;
	for (auto x : a) {
		xorr2 ^= x;
	}
	if (n & 1) cout << min(xorr1, xorr2) << " " << max(xorr2, xorr1) << endl;
	else cout << 0 << " " << max(xorr1, xorr2) << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}