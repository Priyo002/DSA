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


vector<vector<int>> dp;
int f(int i, int j, vector<int>& arr) {
	if (i == j || i + 1 == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int ans = INT_MAX;
	for (int k = i + 1; k < j; k++) {
		ans = min(ans, f(i, k, arr) + f(k, j, arr) + (arr[i] * arr[k] * arr[j]));
	}

	return dp[i][j] = ans;
}


int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int n;
	cin >> n;
	dp.clear();
	dp.resize(1005, vector<int>(1000, -1));
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << f(0, n - 1, arr);

	//Bottom-Up
	// dp.resize(1005, vector<int>(1000, 0));
	// for (int len = 3; len <= n; len++) {
	// 	for (int i = 0; i + len - 1 < n; i++) {
	// 		int j = i + len - 1;
	// 		dp[i][j] = INT_MAX;
	// 		for (int k = i + 1; k < j; k++) {
	// 			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + (arr[i] * arr[k] * arr[j]));
	// 		}
	// 	}
	// }
	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}