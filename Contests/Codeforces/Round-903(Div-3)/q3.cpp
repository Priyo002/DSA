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

	vector<string> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int ans = 0;
	vector<char> v;

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			v.clear();
			v.push_back(s[i][j]);
			v.push_back(s[j][n - i - 1]);
			v.push_back(s[n - i - 1][n - j - 1]);
			v.push_back(s[n - j - 1][i]);

			sort(v);
			for (auto e : v) {
				ans += (v.back() - e);
			}
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