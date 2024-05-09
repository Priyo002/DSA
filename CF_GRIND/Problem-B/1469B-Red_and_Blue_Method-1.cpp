#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
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
vector<int> arr, brr;
vector<vector<int>> dp;

int f(int i, int j) {

	if (i >= n || j >= m) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	int ans = 0LL;

	ans = max(ans, arr[i] + brr[j] + f(i + 1, j + 1));
	ans = max(ans, arr[i] + f(i + 1, j));
	ans = max(ans, brr[j] + f(i, j + 1));

	return dp[i][j] = ans;
}

void solve() {
	cin >> n;

	arr.clear();
	arr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cin >> m;

	brr.clear();
	brr.resize(m);

	for (int i = 0; i < m; i++) {
		cin >> brr[i];
	}

	dp.clear();
	dp.resize(110, vector<int>(110, -1));

	cout << f(0, 0) << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int _t = 1;
	cin >> _t;
	while (_t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}