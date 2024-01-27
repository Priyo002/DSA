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
	int n;
	cin >> n;
	vector<int> f(n + 1, 0);
	int m;
	cin >> m;
	vector<int> l(n + 1, 0);
	vector<int> r(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int L, R;
		cin >> L >> R;
		l[L]++;
		r[R]++;
	}
	f[1] = l[1];
	for (int i = 2; i <= n; i++) {
		f[i] = l[i] - r[i - 1] + f[i - 1];
	}
	vector<int> c(1000005, 0);
	for (int i = 0; i <= n; i++) {
		int coins = f[i];
		c[coins]++;
	}
	for (int i = c.size() - 2; i >= 0; i--) {
		c[i] += c[i + 1];
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << c[x] << endl;
	}
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();


	solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}