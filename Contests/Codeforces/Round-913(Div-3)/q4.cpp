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

#define ss second
#define ff first

void solve() {
	int n;
	cin >> n;

	vector<int> a(n), b(n), c(n);
	for (auto &e : a)     cin >> e;
	for (auto &e : b)     cin >> e;
	for (auto &e : c)     cin >> e;

	multiset<pair<int, int>> x, y;

	for (int i = 0; i < n; i++)
	{
		x.insert({b[i], i});
		y.insert({c[i], i});
	}

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		x.erase({b[i], i});
		y.erase({c[i], i});

		if ((*x.rbegin()).ss == (*y.rbegin()).ss)
			ans = max({ans, a[i] + (*(--x.end())).ff + (*(--(--y.end()))).ff,
			           a[i] + (*(--y.end())).ff + (*(--(--x.end()))).ff
			          });
		else
			ans = max(ans, a[i] + (*(--x.end())).ff + (*(--y.end())).ff);

		x.insert({b[i], i});
		y.insert({c[i], i});
	}

	cout << ans << "\n";
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}