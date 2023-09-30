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
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum1 += a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		sum2 += b[i];
	}
	sort(a), sort(b);

	if (k & 1) {
		if (a[0] < b[0]) {
			sum1 -= a[0];
			sum1 += b[0];
		}
		if (a[0] < b[m - 1]) {
			sum1 -= a[0];
			sum1 += b[m - 1];
		}

	}
	else {
		if (b[0] < a[n - 1]) {
			sum1 -= a[n - 1];
			sum1 += b[0];
		}
	}
	cout << sum1 << endl;
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