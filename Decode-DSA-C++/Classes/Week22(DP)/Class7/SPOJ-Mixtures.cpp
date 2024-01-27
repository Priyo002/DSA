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
};

int dp[105][105];
vector<int> color;

int g(int i, int j) {
	int res = 0;
	for (int m = i; m <= j; m++) {
		res = (res % 100 + color[m] % 100) % 100;
	}
	return res;
}

int ftd(int i, int j) {
	if (i == j) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		ans = min(ans, ftd(i, k) + ftd(k + 1, j) + (g(i, k) * g(k + 1, j)));
	}

	return dp[i][j] = ans;
}

int fbu() {
	memset(dp, 0, sizeof(dp));
	int n = color.size();
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + len - 1;
			int ans = INT_MAX;
			for (int k = i; k <= j - 1; k++) {
				ans = min(ans, dp[i][k] + dp[k + 1][j] + (g(i, k) * g(k + 1, j)));
			}
			dp[i][j] = ans;
		}

	}
	return dp[0][n - 1];
}

void solve() {
	int n;
	while (cin >> n) {
		color.clear();
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			color.push_back(x);
		}
		//memset(dp, -1, sizeof(dp));
		//cout << ftd(0, color.size() - 1) << endl;
		cout << fbu() << endl;
	}

}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();



	solve();


	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}