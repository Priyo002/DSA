#include<bits/stdc++.h>
using namespace std;

#define int long long
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

void solve() {

}

int32_t main() {

	init();

	int k, l, m;
	cin >> k >> l >> m;
	vector<bool> dp(1000005, 0);
	dp[1] = 1, dp[k] = 1, dp[l] = 1;


	//Bottom Up
	for (int i = 2; i <= 1000005; i++) {
		if (i == k || i == l) continue;
		dp[i] = !(dp[i - 1] && ((i - k >= 1) ? dp[i - k] : 1) && ((i - l >= 1) ? dp[i - l] : 1));
	}

	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		if (dp[n] == 1) cout << 'A'; //Winning State
		else cout << 'B';//Loosing State
	}
	return 0;
}