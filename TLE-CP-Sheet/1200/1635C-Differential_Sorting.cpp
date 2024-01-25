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
	cin >> n ;
	vector<int> arr(n), temp;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (is_sorted(arr.begin(), arr.end())) {
		cout << 0 << endl;
		return;
	}
	for (int i = 0; i <= n - 3; i++) {
		arr[i] = arr[n - 2] - arr[n - 1];
	}

	if (is_sorted(arr.begin(), arr.end())) {
		cout << max(0ll, n - 2) << endl;
		for (int i = 0; i <= n - 3; i++) {
			cout << i + 1 << " " << n - 1 << " " << n << endl;
		}
	}
	else cout << -1 << endl;
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