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
	int n, m, a;
	cin >> n >> m;
	multiset<int> mt;
	for (int i = 0; i < n; i++) {
		cin >> a;
		mt.insert(a);
	}
	for (int i = 0; i < m; i++) {
		cin >> a;
		auto it = mt.upper_bound(a);
		if (it == mt.begin()) {
			cout << -1 << endl;
		}
		else {
			cout << *(--it) << endl;
			mt.erase(it);
		}
	}
}

int32_t main() {

	init();

	solve();

}