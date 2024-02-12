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

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n), b(m);
	for (auto&i : a) cin >> i;
	for (auto&i : b) cin >> i;

	vector<int> cnt(k + 1, 0);

	vector<int> a1(k + 1, 0), b1(k + 1, 0);
	for (auto x : a) {
		if (x > k) continue;
		a1[x] = 1;
	}

	for (auto x : b) {
		if (x > k) continue;
		b1[x] = 1;
	}

	vector<int> c(k + 1, 0);

	for (int i = 1; i <= k; i++) {
		if (a1[i] && b1[i]) {
			c[i] = 1;
			a1[i] = b1[i] = 0;
		}
		else if (a1[i] || b1[i]) cnt[i] = 1;
	}
	for (int i = 1; i <= k; i++) {
		if (cnt[i] == 0) {
			if (c[i] == 0) {
				cout << "NO" << endl;
				return;
			}
		}
	}
	int acnt = accumulate(a1.begin(), a1.end(), 0ll);
	int bcnt = accumulate(b1.begin(), b1.end(), 0ll);
	int comm = accumulate(c.begin(), c.end(), 0ll);

	if (acnt > (k / 2) || bcnt > (k / 2)) {
		cout << "NO" << endl;
		return;
	}
	int na = k / 2 - acnt, nb = k / 2 - bcnt;
	comm -= na;
	comm -= nb;
	if (comm < 0) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;

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