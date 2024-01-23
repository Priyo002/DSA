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
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	int ans = 0;
	for (int i = 0; i < (n + 1) / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			int nowi = i, nowj = j;
			int oldnowj = nowj;
			int sum = a[nowi][nowj];
			nowj = n - nowi - 1;
			nowi = oldnowj;
			sum += a[nowi][nowj];
			oldnowj = nowj;
			nowj = n - nowi - 1;
			nowi = oldnowj;
			sum += a[nowi][nowj];
			oldnowj = nowj;
			nowj = n - nowi - 1;
			nowi = oldnowj;
			sum += a[nowi][nowj];
			ans += min(sum, 4 - sum);
		}
	}
	cout << ans << endl;
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