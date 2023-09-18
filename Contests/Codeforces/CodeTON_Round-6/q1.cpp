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
	int n, k, x;
	cin >> n >> k >> x;
	if (n < k) {
		cout << -1 << endl;
		return;
	}
	vector<int> ans;
	for (int i = 0; i < k; i++) {
		ans.pb(i);
	}
	if (ans.back() > x) {
		cout << -1 << endl;
		return;
	}
	if (k == x) x--;
	while (ans.size() != n) {
		ans.pb(x);
	}
	cout << accumulate(ans.begin(), ans.end(), 0) << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}