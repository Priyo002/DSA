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

pair<int, int> ops(char ch, char k) {
	vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int idx1 = ch - '0';
	int idx2 = k - '0';
	int a = 0;
	int i = idx1;
	while (arr[i] != idx2) {
		i++;
		if (i == 10) i = 0;
		a++;
	}
	int b = 0;
	int j = idx1;
	while (arr[j] != idx2) {
		j--;
		if (j == -1) j = 9;
		b++;
	}
	return {a, b};
}

void solve() {
	int n, m;
	cin >> n >> m;
	string s, k;
	cin >> s >> k;
	int ans = INT_MAX;
	for (int i = 0; i + m <= n; i++) {
		int x = 0;
		for (int j = 0; j < m; j++) {
			pair<int, int> p = ops(s[j + i], k[j]);
			x += min(p.first, p.second);
		}
		ans = min(ans, x);
	}
	cout << ans << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}