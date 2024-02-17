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

	vector<pair<int, int>> a, b;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		int y = 1;
		while (x % m == 0) {
			x /= m;
			y *= m;
		}

		if (a.size() && a.back().first == x) {
			a.back().second += y;
		}
		else a.push_back({x, y});
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;

		int y = 1;
		while (x % m == 0) {
			x /= m;
			y *= m;
		}
		if (b.size() && b.back().first == x) {
			b.back().second += y;
		}
		else b.push_back({x, y});
	}



	if (a != b) {
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;
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