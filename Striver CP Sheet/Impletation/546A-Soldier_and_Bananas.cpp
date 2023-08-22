#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const int INF = 1e18;

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
	int k, n, w;
	cin >> k >> n >> w;
	int tc = 0;
	for (int i = 1; i <= w; i++) {
		tc += (i * k);
	}
	if (tc - n >= 0)
		cout << tc - n;
	else cout << 0;
}

int32_t main() {

	init();

	solve();

}