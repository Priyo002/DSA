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
	int n;
	cin >> n;

	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	if (a[1] > n) {
		cout << "NO" << endl;
		return;
	}

	vector<int> b(n + 1);

	for (int i = 1; i <= n; i++) {
		b[a[i]]++;
	}

	for (int i = n - 1; i > 0; i--) {
		b[i] += b[i + 1];
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;


}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}