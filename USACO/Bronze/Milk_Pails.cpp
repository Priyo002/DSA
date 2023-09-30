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

int x, y, m;
int ans = INT_MIN;

vector<int> dp;

void f(int n) {
	if (n > m) return;
	if (dp[n] != -1) {
		ans = max(ans, dp[n]);
		return;
	}
	ans = max(ans, n);
	dp[n] = ans;
	f(n + x);
	f(n + y);
}

void solve() {

	for (int i = 0; i <= m; i++) {
		if (i * x > m) break;
		for (int j = 0; j <= m; j++) {
			int temp = (i * x) + (j * y);
			if (temp > m) break;
			ans = max(ans, temp);
		}
	}
}

int32_t main() {

	//init();
	//clock_t time_req;
	//time_req = clock();

	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

	dp.clear();
	dp.resize(1004, -1);
	cin >> x >> y >> m;
	//f(0);
	solve();
	cout << ans;

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}