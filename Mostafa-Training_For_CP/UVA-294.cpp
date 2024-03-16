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

int f(int n) {

	int cnt = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			cnt++;
			if (n / i != i) {
				cnt++;
			}
		}
	}
	return cnt;
}

void solve() {
	int l, u;
	cin >> l >> u;

	int cnt = 0;
	int ans = INT_MAX;
	for (int i = l; i <= u; i++) {
		int k = f(i);
		if (k > cnt) {
			ans = i;
			cnt = k;
		}
	}

	cout << "Between " << l << " and " << u << ", ";
	cout << ans << " has " << "a" << " maximum of " << cnt;
	cout << " divisors." << endl;
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