#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
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

int n, m;
int a[100013];
int dp[100013][113];
int solve(int i, int p) {
	if (i == n)
		return 1;
	if (dp[i][p] != -1) return dp[i][p];
	if (a[i] == 0) {

		int total = 0;
		for (int x = max(1LL, p - 1); x <= min(m, p + 1); x++) {
			total += solve(i + 1, x);
		}

		return dp[i][p] = total % mod;
	}
	else {
		if (abs(a[i] - p) > 1) return 0;
		return dp[i][p] = solve(i + 1, a[i]) % mod;
	}
}

int32_t main() {

	init();

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	memset(dp, -1, sizeof dp);

	if (a[0] == 0) {
		int total = 0;
		for (int x = 1; x <= m; x++) {
			total += solve(1, x);
		}
		cout << total % mod << endl;
	}
	else {
		cout << solve(1, a[0]) % mod << endl;
	}

}