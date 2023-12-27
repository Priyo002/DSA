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


int dp[10000];
int f(vector<int>& arr, int n) {
	if (n == 0) return 0;
	if (dp[n] != -1) return dp[n];
	int ans = INT_MIN;
	for (int i = 0; i < arr.size(); i++) {
		if (n - arr[i] < 0) continue;
		ans = max(ans, 1 + f(arr, n - arr[i]));
	}
	return dp[n] = ans;
}

void solve() {
	int n, a, b, c;
	cin >> n;
	vector<int> arr(3);
	for (int i = 0; i < 3; i++) cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << f(arr, n);
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();


	solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}