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
int n, x;
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
	vector<vector<int>> dp(n + 1, vector<int>(x + 1));
	for (int i = 1; i <= n; i++) {
		int curr_cost = price[i - 1];
		int curr_pages = pages[i - 1];
		for (int j = 1; j <= x; j++) {
			/*
			 * if the current book is not bought, the the number of pages is
			 * the same as number of pages bought for first i-1 books using
			 * j amount of money
			 */
			dp[i][j] = dp[i - 1][j];
			if (curr_cost <= j) {
				/*
				 * if the current book can be bought, then store the most
				 * number of pages using the remaining money after buying
				 * the current book plus the pages for the current book.
				 */
				dp[i][j] = max(dp[i][j], dp[i - 1][j - curr_cost] + curr_pages);
			}
		}
	}
	return dp[n][x];
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	//memset(dp, -1, sizeof(dp));

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