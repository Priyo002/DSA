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

int dp[22][1 << 22];

int f(int i, int mask, int n, vector<vector<int>>& c) {
	if (i == n + 1) {
		if (mask == 0) return 1;
		return 0;
	}
	if (dp[i][mask] != -1) return dp[i][mask];
	int ans = 0;
	for (int w = 1; w <= n; w++) {
		bool available = (mask & (1 << (w - 1)));
		if (available && c[i][w]) {
			int off = mask ^ (1 << (w - 1));
			ans = (ans % mod + f(i + 1, off, n, c) % mod) % mod;
		}
	}

	return dp[i][mask] = ans;
}

void solve() {

	int n;
	cin >> n;
	vector<vector<int>> c(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << f(1, (1 << n) - 1, n, c) << endl;
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