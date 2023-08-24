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
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		if (ch == 'B') v[i] = 1;
		else v[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		v[i] = v[i] + v[i - 1];
	}
	int w = k - v[k - 1] ;
	int i = 1;
	int j = k;
	int ans = w;
	while (j < n) {
		w = (j - i + 1) - (v[j] - v[i - 1]) ;
		i++;
		j++;
		ans = min(ans, w);
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