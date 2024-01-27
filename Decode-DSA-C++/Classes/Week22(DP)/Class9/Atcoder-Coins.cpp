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

double dp[3005][3005];

double f(vector<double>& p, int i, int x) {
	if (x == 0) return 1;
	if (i == -1) return 0;

	if (dp[i][x] > -0.9) return dp[i][x];
	return dp[i][x] = f(p, i - 1, x - 1) * p[i] + f(p, i - 1, x) * (1 - p[i]);
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int n;
	cin >> n;
	vector<double> p(n);
	for (int i = 0; i < n; i++) cin >> p[i];

	memset(dp, -1, sizeof(dp));
	cout << fixed << setprecision(9) << f(p, n - 1, (n + 1) / 2);


	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}