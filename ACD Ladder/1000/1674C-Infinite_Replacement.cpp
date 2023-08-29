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

int powr(int c1) {
	int res = 1;
	int a = 2;
	while (c1) {
		if (c1 & 1) res *= a;
		c1 = (c1 >> 1);
		a *= a;
	}
	return res;
}

void solve() {
	string s, t;
	cin >> s >> t;
	int c1 = s.size();
	int c2 = 0;
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == 'a') c2++;
	}
	if (c2 == 1 && t.size() == 1) {
		cout << 1 << endl;
		return;
	}
	if (c2 >= 1) {
		cout << -1 << endl;
		return;
	}
	cout << powr(c1) << endl;
}

int32_t main() {

	init();


	int t;
	cin >> t;
	while (t--)
		solve();

}