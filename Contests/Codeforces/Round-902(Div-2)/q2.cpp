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
	int n, p;
	cin >> n >> p;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i].second;
	for (int i = 0; i < n; i++) cin >> arr[i].first;
	sort(arr);

	int ans = 0, tr = 0;
	for (int i = 0; i < n; i++) {
		int cost = arr[i].first;
		int res = arr[i].second;
		if (cost > p || tr == n - 1) break;
		if (res < (n - tr - 1)) {
			ans += (cost * res);
			tr += res;
		}
		else {
			ans += (cost * (n - tr - 1));
			tr = n - 1;
			break;
		}
	}
	ans += (p * (n - tr));
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