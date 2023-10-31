#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1000000007;
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

vector<int> coins, dp;
int f(int sum) {
	if (sum == 0) return 1;
	if (dp[sum] != -1) return dp[sum];
	int ans = 0;
	for (int i = 0; i < coins.size(); i++) {
		if (sum - coins[i] < 0) continue;
		ans = (ans % mod + f(sum - coins[i]) % mod) % mod;
	}
	return dp[sum] = ans % mod;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int n, x;
	cin >> n >> x;
	coins.resize(n);
	dp.resize(1000008, -1);
	for (int i = 0; i < n; i++) cin >> coins[i];

	cout << f(x);
	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}