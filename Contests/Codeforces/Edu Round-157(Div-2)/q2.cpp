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
	vector<int> arr(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> arr[i];
	}
	sort(arr);
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		x[i] = arr[i];
		y[i] = arr[n + i];
	}
	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans += (abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]));
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		cout << x[i] << " " << y[i] << endl;
	}
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