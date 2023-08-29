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
	int n;
	cin >> n;
	int k = n - 1;
	cout << 2 << endl;
	double a = n;
	double b = n - 1;
	while (k--) {
		int k = ceil((a * 1.0 + b * 1.0) / 2.0);
		cout << a << " " << b << endl;
		a = k;
		b--;
	}
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}