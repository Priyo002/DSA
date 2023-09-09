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
	int y, x;
	cin >> y >> x;
	if (y > x) {
		if (y & 1) {
			cout << ((y - 1) * (y - 1)) + 1 + (x - 1) << endl;
		}
		else {
			cout << (y * y) - (x - 1) << endl;
		}
	}
	else {
		if (x & 1) {
			cout << (x * x) - (y - 1) << endl;
		}
		else {
			cout << ((x - 1) * (x - 1)) + 1 + (y - 1) << endl;
		}
	}
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}