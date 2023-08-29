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

int n, m;
void solve() {
	cin >> n >> m;
	if (m % n != 0) {
		cout << -1;
		return;
	}
	int d = m / n;
	int cnt = 0;
	while ((d % 2 == 0)) {
		d /= 2;
		cnt++;
	}
	while ((d % 3 == 0)) {
		d /= 3;
		cnt++;
	}
	if (d == 1) cout << cnt;
	else cout << -1;
}

int32_t main() {

	init();


	solve();

}