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
	int a, b, r;
	cin >> a >> b >> r;

	int ans = 0;
	int mn = INT_MAX;
	if (r >= INT_MAX) {
		cout << "n";
		cout << endl;
		return;
	}
	for (int i = 0; i <= r; i++) {
		int k1 = a ^ i, k2 = b ^ i;
		if (abs(k1 - k2) <= mn) {
			ans = i;
			mn = abs(k1 - k2);
		}
	}
	cout << ans << " " << mn << endl;
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