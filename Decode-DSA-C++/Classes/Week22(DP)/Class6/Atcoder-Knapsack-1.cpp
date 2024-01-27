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
//vector<vector<int>> dp(105, vector<int>(100005, -1));

// int f(vector<int>&wts, vector<int>&val, int idx, int W) {
// 	if (idx == wts.size()) return 0;
// 	if (dp[idx][W] != -1) return dp[idx][W];
// 	int ans = INT_MIN;
// 	ans = max(ans, f(wts, val, idx + 1, W));
// 	if (wts[idx] <= W) {
// 		ans = max(ans, val[idx] + f(wts, val, idx + 1, W - wts[idx]));
// 	}
// 	return dp[idx][W] = ans;
// }

vector<vector<int>> dp;
int fbu(vector<int>&wts, vector<int>&val, int W) {
	dp.resize(105, vector<int> (100005, 0));
	int n = wts.size();
	for (int idx = n - 1; idx >= 0; idx--) {
		for (int j = 0; j <= W; j++) {
			int ans = INT_MIN;
			ans = max(ans, dp[idx + 1][j]);
			if (wts[idx] <= j) {
				ans = max(ans, val[idx] + dp[idx + 1][j - wts[idx]]);
			}
			dp[idx][j] = ans;
		}

	}
	return dp[0][W];
}

int32_t main() {

	init();

	int n, W;
	cin >> n >> W;
	vector<int> wts(n), val(n);
	for (int i = 0; i < n; i++) {
		cin >> wts[i] >> val[i];
	}
	//cout << f(wts, val, 0, W);
	cout << fbu(wts, val, W);
}