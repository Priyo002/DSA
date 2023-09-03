#include<bits/stdc++.h>
using namespace std;

#define int long long
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
	vector<int> a(n + 1);
	vector<int> b(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}
	vector<int> fa(n + n + 1);
	vector<int> fb(n + n + 1);
	int p = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (a[i] != a[i - 1])
		{
			fa[a[i - 1]] = max(fa[a[i - 1]], i - p);
			p = i;
		}
	}
	fa[a[n]] = max(fa[a[n]], n - p + 1);

	p = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (b[i] != b[i - 1])
		{
			fb[b[i - 1]] = max(fb[b[i - 1]], i - p);
			p = i;
		}
	}
	fb[b[n]] = max(fb[b[n]], n - p + 1);

	int ans = 0;
	for (int i = 1; i <= n + n; ++i)
	{
		ans = max(ans, fa[i] + fb[i]);
	}

	cout << ans << '\n';
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}