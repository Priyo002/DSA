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

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) cin >> coins[i];

	vector<int> dp(x + 1, 0);
	for (auto c : coins) {
		if (c <= x)
			dp[c] = (dp[c] % mod + 1) % mod;
		for (int i = 0; i < dp.size(); i++) {
			if (i - c >= 0)
				dp[i] = (dp[i] % mod + dp[i - c] % mod) % mod;
		}
	}
	cout << dp[x] << endl;

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}