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

//https://atcoder.jp/contests/dp/tasks/dp_d

// vector<vector<int>> dp(105, vector<int>(100005, -1));
// int f(vector<int>&wts, vector<int>&val, int idx, int tv) {
// 	if (tv == 0) return 0;
// 	if (idx == wts.size()) return INT_MAX;
// 	if (dp[idx][tv] != -1) return dp[idx][tv];
// 	int ans = INT_MAX;
// 	ans = min(ans, f(wts, val, idx + 1, tv));
// 	if (val[idx] <= tv) {
// 		ans = min(ans, wts[idx] + f(wts, val, idx + 1, tv - val[idx]));
// 	}
// 	return dp[idx][tv] = ans;
// }

vector<vector<int>> dp;
int fbu(vector<int>&wts, vector<int>&val, int tv, int W) {
	dp.resize(105, vector<int> (100005, INT_MAX));
	int n = wts.size();

	for (int i = 0; i < dp.size(); i++) {
		dp[i][0] = 0;
	}

	for (int idx = n - 1; idx >= 0; idx--) {
		for (int j = 0; j <= tv; j++) {
			int ans = INT_MAX;
			ans = min(ans, dp[idx + 1][j]);
			if (val[idx] <= j) {
				ans = min(ans, wts[idx] + dp[idx + 1][j - val[idx]]);
			}
			dp[idx][j] = ans;
		}

	}
	int res = -1;
	for (int i = 0; i <= n * 1000; i++) {
		if (dp[0][i] <= W)
			res = i;
	}
	return res;
}

int32_t main() {

	init();

	int n, W;
	cin >> n >> W;
	vector<int> wts(n), val(n);
	for (int i = 0; i < n; i++) {
		cin >> wts[i] >> val[i];
	}
	// int res = -1;
	// for (int i = 0; i <= n * 1000; i++) {
	// 	if (f(wts, val, 0, i) <= W)
	// 		res = i;
	// }
	// cout << res;

	cout << fbu(wts, val, n * 1000, W);
}