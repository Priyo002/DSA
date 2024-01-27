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

/* Question :
 * Given a Number you can perform any of the following
 * operations on it some no. of times
 *
 * 1. Reduce n to n-1
 * 2. if n is divisible by 2 make it n/2
 * 3. if n is divisible by 3 make it n/3
 *
 * find out in how many minimum steps you can reduce n to 1
 */


vector<int> dp;

//top-down dp
int ftd(int n) {
	if (n == 1) return 0;
	if (n == 2 || n == 3) return 1;
	if (dp[n] != -1) return dp[n];
	return dp[n] = 1 + min({ftd(n - 1), (n % 3 == 0) ? ftd(n / 3) : INF, (n % 2 == 0) ? ftd(n / 2) : INF});

}

//bottom-up
int fbu(int n) {
	dp.clear();
	dp.resize(n + 1, -1);
	dp[1] = 0, dp[2] = 1, dp[3] = 1;
	for (int i = 4; i <= n; i++) {
		dp[i] = 1 + min({dp[i - 1], (i % 2 == 0) ? dp[i / 2] : INF, (i % 3 == 0) ? dp[i / 3] : INF});
	}
	return dp[n];
}

int32_t main() {

	init();

	int n;
	cin >> n;
	dp.clear();
	dp.resize(n + 1, -1);
	cout << ftd(n) << " " << fbu(n);

}