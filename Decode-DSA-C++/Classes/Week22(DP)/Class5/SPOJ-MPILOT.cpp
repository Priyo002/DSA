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


int n;
int dp[10015][10000];
vector<int> cap, as;
int cal(int i, int x) {
	if (dp[i][x] != -1) return dp[i][x];
	if (i == n) return 0;

	if (x == 0)
		return dp[i][x] = cal(i + 1, x + 1) + as[i];
	else if (x == n - i)
		return dp[i][x] = cal(i + 1, x - 1) + cap[i];
	else
		return dp[i][x] = min(cal(i + 1, x + 1) + as[i], cal(i + 1, x - 1) + cap[i]);

}

int32_t main() {

	init();

	memset(dp, -1, sizeof dp);
	cin >> n;
	cap.resize(n);
	as.resize(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		cap[i] = a;
		as[i] = b;
	}
	dp[0][0] = as[0] + cal(1, 1);
	cout << dp[0][0];


}