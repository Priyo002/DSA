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
	int n, m, a;
	cin >> n >> m;
	vector<int> w;
	vector<int> r;
	for (int i = 0; i < n; i++) {
		cin >> a;
		w.pb(a);
	}
	for (int i = 0; i < m; i++) {
		cin >> a;
		r.pb(a);
	}
	int sum = r.back();
	r.pop_back();
	for (int i = 0; i < r.size(); i++) {
		w.pb(r[i]);
	}
	sort(w.begin(), w.end(), greater<int>());

	for (int i = 1; i < n; i++) {
		sum += w[i - 1];
	}
	cout << sum << endl;




}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}