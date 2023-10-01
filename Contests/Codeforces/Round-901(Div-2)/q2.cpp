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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), b(m);

	vector<multiset<int>> st(2);

	int mn = INT_MAX;
	int mx = INT_MIN;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st[0].insert(a[i]);
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		st[1].insert(b[i]);
		mn = min(mn, b[i]);
		mx = max(mx, b[i]);
	}

	auto erase = [&] (int idx, int val) {
		st[idx].erase(st[idx].find(val));
	};

	int turn = 0;
	while (k > 0) {
		int small = *st[turn].begin();
		int big = *st[turn ^ 1].rbegin();

		if (small == mn && big == mx) {
			k &= 1; //k = k%2;
			if (k == 0) break;
		}
		if (small < big) {
			erase(turn, small);
			erase(turn ^ 1, big);
			st[turn].insert(big);
			st[turn ^ 1].insert(small);
		}
		k--;
		turn ^= 1;
	}

	int ans = 0;
	for (auto &x : st[0]) {
		ans += x;
	}
	cout << ans << endl;

}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}