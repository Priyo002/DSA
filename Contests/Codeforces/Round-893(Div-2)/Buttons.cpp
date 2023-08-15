#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define inf 1e18
const int mod = 1e9 + 7;

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
	int a, b, c;
	cin >> a >> b >> c;
	if (c & 1) {
		a += (c / 2 + 1);
		b += (c / 2);
	}
	else {
		a += (c / 2);
		b += (c / 2);
	}
	string k = a > b ? "First" : "Second";
	cout << k << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}