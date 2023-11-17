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

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	int mn = INT_MAX, mx = INT_MIN;
	int ans = INT_MIN;
	for (auto&x : arr) {
		cin >> x;
		mx = max(mx, x);
		mn = min(mn, x);
	}
	ans = max(ans, abs(mx - mn));
	for (int i = 1; i < n; i++) arr[i] += arr[i - 1];

	for (int k = 2; k <= n; k++) {
		if ((n % k == 0) && k != n) {
			int j = k - 1;
			int maxi = arr[j];
			int mini = arr[j];
			j += k;
			while (j < n) {
				int temp = arr[j] - arr[j - k];
				maxi = max(maxi, temp);
				mini = min(mini, temp);
				j += k;
			}
			ans = max(ans, abs(maxi - mini));
		}
	}
	cout << ans << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}