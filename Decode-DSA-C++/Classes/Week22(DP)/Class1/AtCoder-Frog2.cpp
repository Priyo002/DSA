#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const int INF = 1e18;

void init() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif
}

vector<int>h, dp;
int k;


//Top down approach
// int f(int i) {
// 	if (i >= h.size()) return INT_MAX;
// 	if (i == h.size() - 1) return 0;
// 	if (dp[i] != -1) return dp[i];
// 	int ans = INT_MAX;
// 	for (int j = 1; j <= k; j++) {
// 		if (i + j >= h.size()) break;
// 		ans = min(ans, abs(h[i] - h[i + j]) + f(i + j));
// 	}
// 	return dp[i] = ans;
// }


//Bottom-Up Approach
int fbu() {
	int n = h.size();
	dp.resize(100005, INT_MAX);
	dp[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 1; j <= k; j++) {
			if (i + j >= h.size()) break;
			dp[i] = min(dp[i], abs(h[i] - h[i + j]) + dp[i + j]);
		}
	}
	return dp[0];
}

int32_t main() {

	init();

	int n;
	cin >> n >> k;
	h.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	//cout << f(0) << endl;
	cout << fbu();
	return 0;

}