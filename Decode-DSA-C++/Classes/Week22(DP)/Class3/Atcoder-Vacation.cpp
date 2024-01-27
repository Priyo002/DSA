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

int32_t main() {

	init();

	int n;
	cin >> n;
	vector<vector<int>> dp(n, vector<int>(3, 0));

	//base Case
	int a, b, c; //a->0 , b->1 , c->2
	cin >> a >> b >> c;
	dp[0][0] = a;
	dp[0][1] = b;
	dp[0][2] = c;

	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		//ith day -> a;
		dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
		//ith day -> b;
		dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
		//ith day -> c;
		dp[i][2] = c + max(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

}