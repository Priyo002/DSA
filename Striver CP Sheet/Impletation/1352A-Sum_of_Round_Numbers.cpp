#include<bits/stdc++.h>
using namespace std;

#define int long long
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
	int n;
	cin >> n;
	vector<int> v;
	int x = 1;
	while (n) {
		int rem = n % 10;
		int temp = rem * x;
		if (temp) v.pb(temp);
		x *= 10;
		n /= 10;
	}
	cout << v.size() << endl;
	for (auto x : v) cout << x << " ";
	cout << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}