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


vector<int> dp((1 << 16), INT_MAX);
vector<int> sum((1 << 16), 0);

int calc(vector<vector<int>>& compat, int mask) {
	int ans = 0;
	for (int i = 0; i <= 16; i++) {
		for (int j = i + 1; j <= 16; j++) {
			if ((mask & (1 << i)) != 0 && (mask & (1 << j)) != 0) {
				ans += compat[i][j];
			}
		}
	}
	return ans;
}

void precompute(vector<vector<int>>& compat, int n) {
	for (int mask = 1; mask <= ((1 << n) - 1); mask++) {
		sum[mask] = calc(compat, mask);
	}
}

int f(vector<vector<int>>& compat, int mask) {
	if (mask == 0) {
		return 0;
	}
	if (dp[mask] != INT_MAX) return dp[mask];

	int ans = INT_MIN;
	for (int g = mask; g != 0; g = ((g - 1)&mask)) {
		ans = max(ans, sum[g] + f(compat, (mask ^ g)));
	}

	return dp[mask] = ans;
}


void solve() {
	int n;
	cin >> n;
	vector<vector<int>> compat(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> compat[i][j];
		}
	}
	precompute(compat, n);
	cout << f(compat, ((1 << n) - 1));
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