#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
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
	vector<int> ans = {n};
	while (__builtin_popcount(n) > 1) {
		n -= (n & -n);
		ans.push_back(n);
	}
	while (n > 1) {
		ans.push_back(n / 2);
		n /= 2;
	}
	cout << ans.size() << "\n";
	for (int i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}