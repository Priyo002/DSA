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
	int n, h;
	cin >> n >> h;
	vector<int> arr(n);
	int hi = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		hi = max(hi, arr[i]);
	}
	int lo = 0;
	int ans = 0;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		int sum = mid;
		int str = h;
		for (int i = 0; i < n; i++) {
			if (sum >= arr[i]) continue;
			str -= arr[i];
		}
		if (str > 0) {
			hi = mid - 1;
			ans = mid;
		}
		else lo = mid + 1;
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