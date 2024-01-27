#include<bits/stdc++.h>
using namespace std;

#define int long long
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

//https://www.spoj.com/problems/GNYR09F/

int dp[105][105][2];

int f(int n, int k, int lastBit) {
	if (n == 0) return 0;
	if (n == 1) {
		if (k == 0) return 1;
		else return 0;
	}
	if (dp[n][k][lastBit] != -1) return dp[n][k][lastBit];
	if (lastBit == 1) {
		return dp[n][k][lastBit] = f(n - 1, k, 0) + f(n - 1, k - 1, 1);
	}
	else return dp[n][k][lastBit] = f(n - 1, k, 0) + f(n - 1, k, 1);
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--) {
		int num, n, k;
		cin >> num >> n >> k;
		memset(dp, -1, sizeof dp);
		int ans = f(n, k, 0) + f(n, k, 1);
		cout << num << " " << ans << endl;
	}
}