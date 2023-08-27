#include<bits/stdc++.h>
using namespace std;

#define int long long int
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
	int x, y, n;
	cin >> x >> y >> n;
	vector<int> arr(n);
	int cnt = 1;
	arr[0] = x;
	arr[n - 1] = y;
	for (int i = n - 2; i >= 1; i--) {
		arr[i] = arr[i + 1] - cnt;
		cnt++;
	}
	for (int i = 1; i <= n - 2; i++) {
		int diff1 = arr[i] - arr[i - 1];
		int diff2 = arr[i + 1] - arr[i];
		if (diff1 - diff2 <= 0) {
			cout << -1 << endl;
			return;
		}
	}
	for (auto x : arr) cout << x << " ";
	cout << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}