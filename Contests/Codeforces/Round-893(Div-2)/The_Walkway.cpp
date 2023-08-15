#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define inf 1e18
const int mod = 1e9 + 7;

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
	int n, m, d, x;
	cin >> n >> m >> d;
	vector<int> arr;
	vector<int> v;
	v.pb(1);
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (v.back() != x) v.pb(x);
	}
	if (v.back() != n) v.pb(n);
	int cnt = 0;
	vector<int> pre;
	vector<int> suff;
	for (int i = 1; i < v.size() - 1; i++) {
		int k = v[i + 1] - v[i] - 1;
		cnt += (k / d);
		pre.pb(cnt);
	}
	cnt = 0;
	for (int i = v.size() - 1; i > 0; i--) {
		int k = abs(v[i] - v[i - 1] - 1);
		cnt += (k / d);
		suff.pb(cnt);
	}
	cout << min(suff.front(), pre.back()) << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}