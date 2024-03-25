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
	int k, x;
	cin >> k >> x;

	int lo = 1, hi = k;

	int ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int t = (mid * (mid + 1) ) / 2;

		if (t <= x) {
			ans = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	int temp = (ans) * (ans + 1) / 2;

	if ( temp >= x) {
		cout << ans << endl;
		return;
	}

	x -= temp;

	int cnt = 1;

	lo = 1, hi = k - 1;

	if (lo > hi) {
		cout << ans << endl;
		return;
	}

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		int t = (k * (k - 1)) / 2;
		t -= (mid * (mid - 1)) / 2;

		if (t < x) {
			hi = mid - 1;
		}
		else {
			cnt = mid;
			lo = mid + 1;
		}
	}

	cout << ans + ((k - 1) - cnt + 1) << endl;
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