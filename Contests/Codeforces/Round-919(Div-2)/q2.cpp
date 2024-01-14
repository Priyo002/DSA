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
	int n, k, x;
	cin >> n >> k >> x;

	vector<int> temp(n);

	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}
	sort(temp);
	vector<int> arr = temp;

	for (int i = 1; i < n; i++) {
		arr[i] += arr[i - 1];
	}

	int ans = INT_MIN;
	if (k == n) {
		ans = 0;
	}
	k++;
	for (int i = n - 1; i >= 0 && k--; i--) {
		int t;
		if (i - x >= 0) {
			t = arr[i] - 2 * (arr[i] - arr[i - x]);
		}
		else {
			t = -arr[i];
		}
		ans = max(ans, t);
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