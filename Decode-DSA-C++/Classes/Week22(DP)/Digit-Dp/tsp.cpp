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

int grid[4][4] = {
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};

int dp[10][(1 << 10)];

int tsp(int curr, int mask, int n) {
	if (mask == (1 << n) - 1) {
		return grid[curr][0];
	}

	if (dp[curr][mask] != -1) return dp[curr][mask];

	int ans = INT_MAX;
	for (int neigh = 0; neigh < n; neigh++) {
		if ((mask & (1 << neigh)) == 0) {
			ans = min(ans, grid[curr][neigh] + tsp(neigh, (mask | (1 << neigh)), n));
		}
	}
	return dp[curr][mask] = ans;
}



int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	memset(dp, -1, sizeof(dp));
	cout << tsp(0, 1, 4) << endl;

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}