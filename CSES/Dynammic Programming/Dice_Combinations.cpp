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


vector<int> dp(1000006, -1);

int f(int n) {
	if (n == 0) return 1;

	if (dp[n] != -1) return dp[n];
	int sum = 0;
	for (int i = 1; i <= 6; i++) {
		if (n - i < 0) continue;
		sum = ((sum % mod) + (f(n - i) % mod)) % mod;
	}
	return dp[n] = sum % mod;
}


//Bottom-Up
int fbu(int n) {
	dp[0] = 1;
	for (int k = 1; k <= n; k++) {
		int sum = 0;
		for (int i = 1; i <= 6; i++) {
			if (k - i < 0) continue;
			sum = ((sum % mod) + (dp[k - i] % mod)) % mod;
		}
		dp[k] = sum % mod;
	}
	return dp[n];
}
int32_t main() {

	init();

	int t;
	cin >> t;
	// cout << f(t);
	// cout << endl;
	cout << fbu(t);

	return 0;

}