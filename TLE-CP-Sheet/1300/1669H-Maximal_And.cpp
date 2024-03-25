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
	int n, k;
	cin >> n >> k;

	vector<int> bits(31, 0), arr(n);

	for (auto &i : arr) cin >> i;

	for (auto x : arr) {
		for (int i = 0; i < 31; i++) {
			int bit = ((1 << i)&x);
			bits[i] +=	(bit ? 1 : 0);
		}
	}

	for (int i = 30; i >= 0; i--) {

		int zero = n - bits[i];

		if (zero <= k) {
			k -= zero;
			bits[i] = 1;
		}
		else {
			bits[i] = 0;
		}
	}

	int ans = 0;

	for (int i = 0; i < 31; i++) {
		if (bits[i]) {
			ans += (1 << i);
		}
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