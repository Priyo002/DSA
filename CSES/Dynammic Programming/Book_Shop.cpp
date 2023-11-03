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

vector<int> price, pages;
//int dp[100005][1005];

// int f(int sum, int i) {
// 	if (i == price.size()) return 0;
// 	if (dp[sum][i] != -1) return dp[sum][i];
// 	int ans = INT_MIN;
// 	if (sum - price[i] >= 0)
// 		ans = max(ans, pages[i] + f(sum - price[i], i + 1));
// 	ans = max(ans, f(sum, i + 1));
// 	return dp[sum][i] = ans;
// }

int fbu(int sum) {
	vector<vector<int>> dp(100005, vector<int> (1005, 0));

	for (int j = 0; j <= sum; j++) {
		int ans = INT_MIN;
		for (int i = price.size() - 1; i >= 0; i--) {
			if (sum - price[i] >= 0)
				ans = max(ans, pages[i] + dp[j - price[i]][i + 1]);
			ans = max(ans, dp[j][i + 1]);
			dp[j][i] = ans;
		}
	}
	return dp[sum][0];
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	//memset(dp, -1, sizeof(dp));
	int n, x;
	cin >> n >> x;
	price.resize(n);
	pages.resize(n);

	for (int i = 0; i < n; i++) cin >> price[i];
	for (int i = 0; i < n; i++) cin >> pages[i];


	cout << fbu(x);
	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}