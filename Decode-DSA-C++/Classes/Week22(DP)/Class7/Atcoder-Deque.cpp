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

int dp[3005][3005];
int arr[3005];

int f(int i, int j) {
	if (i == j) return arr[i];
	if (dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = max(arr[i] - f(i + 1, j), arr[j] - f(i, j - 1));
}

int fbu(int n) {
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; i++) {
		dp[i][i] = arr[i];
	}

	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
		}
	}
	return dp[0][n - 1];
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	//cout << f(0, n - 1);
	cout << fbu(n);
	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}