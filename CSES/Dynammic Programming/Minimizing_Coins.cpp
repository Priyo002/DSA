#include<bits/stdc++.h>
using namespace std;

//#define int long long int
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

int n, m;
vector<int> coins, dp(1000006, -2);

int f(int sum) {
	if (sum == 0) return 0;
	if (dp[sum] != -2) return dp[sum];
	int res = INT_MAX;
	for (int i = 0; i < coins.size(); i++) {
		if (sum < coins[i]) continue;
		res = min(res, f(sum - coins[i]));
	}
	if (res == INT_MAX) return dp[sum] = INT_MAX;
	return dp[sum] = 1 + res;
}

int main() {

	init();

	cin >> n >> m;
	coins.clear();
	coins.resize(n);
	for (int i = 0; i < n; i++) cin >> coins[i];
	int ans = f(m);
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
}