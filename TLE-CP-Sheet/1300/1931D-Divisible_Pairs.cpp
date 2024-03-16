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
	int n, x, y;
	cin >> n >> x >> y;

	vector<int> arr(n);
	for (auto&i : arr) cin >> i;

	map<pair<int, int>, int> mp;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int rem = (arr[i] % x);
		int k1 = ((x - rem) % x);

		rem = (((arr[i] * -1) % y) + y) % y;
		int k2 = ((y - rem) % y);

		ans += mp[ {k1, k2}];

		mp[ {(arr[i] % x), (arr[i] % y)}]++;
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