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
	int n, m, x, y, d;
	cin >> n >> m >> x >> y >> d;
	x--, y--;
	int x1 = x - d, x2 = x + d;
	int y1 = y - d, y2 = y + d;
	if ((x1 <= 0 && x2 >= n - 1) || (y1 <= 0 && y2 >= m - 1) || (x1 <= 0 && y1 <= 0) || (x2 >= n - 1 && y2 >= m - 1))
		cout << -1;
	else cout << n + m - 2;
	cout << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}