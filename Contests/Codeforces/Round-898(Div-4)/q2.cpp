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
	int n;
	cin >> n;
	vector<int> arr(n);
	int z = 0;
	int mini = INT_MAX;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 0) z++;
		if (arr[i] < mini) {
			mini = arr[i];
			idx = i;
		}
	}
	if (z > 1) {
		cout << 0 << endl;
		return;
	}
	int prod = 1;
	if (z == 1) {
		for (auto x : arr) {
			if (x) prod *= x;
		}
		cout << prod << endl;
		return;
	}
	arr[idx]++;
	for (auto x : arr) {
		prod *= x;
	}
	cout << prod << endl;

}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}