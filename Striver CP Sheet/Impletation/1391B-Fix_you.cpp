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
	int n, m, cnt = 0;
	cin >> n >> m;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

	}
	for (int i = 0; i < n; i++) {
		string s = arr[i];
		if (s[m - 1] == 'R') cnt++;
		if (i == n - 1) {
			for (int j = 0; j < m; j++) {
				if (s[j] == 'D') cnt++;
			}
		}
	}
	cout << cnt << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}