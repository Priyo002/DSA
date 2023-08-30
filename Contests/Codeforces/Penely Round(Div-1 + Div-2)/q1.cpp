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
	int n, a, q;
	cin >> n >> a >> q;
	string s;
	cin >> s;
	if (n == a) {
		cout << "YES" << endl;
		return;
	}
	int cnt = a, p = 0;
	for (int i = 0; i < q; i++) {
		if (s[i] == '+') {
			cnt++;
			p++;
		}
		else cnt--;
		if (cnt == n) {
			cout << "YES" << endl;
			return;
		}
	}
	if (a + p >= n) {
		cout << "MAYBE";
	}
	else cout << "NO";
	cout << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}