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
	double l, v1, v2;
	cin >> l >> v1 >> v2;
	int t = ceil(l / v1);
	int h = ceil(l / v2);
	if (h >= t) {
		cout << -1 << endl;
		return;
	}
	cout << t - h - 1 << endl;

}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}