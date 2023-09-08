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
	int l, r; cin >> l >> r;
	if (l == r && l % 2) {
		bool sac = false;
		for (int i = 2; i * i <= l; i++) {
			if (l % i == 0) {
				cout << i << " " << l - i << endl;
				sac = true;
				break;
			}
		}
		if (!sac) {
			cout << -1 << endl;
		}
		return;
	}

	l = l / 2 + l % 2;
	r =  r / 2 ;

	int ans = -1;
	if (r == l && l != 1) {
		ans = l;
	} else if (r > l) {
		ans = l + 1;
	}
	if (ans != -1) {
		cout << ans << " " << ans << endl;
	}
	else {
		cout << ans << endl;
	}

}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}