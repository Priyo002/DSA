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

bool check(vector<int>& temp) {
	for (int i = 1; i < temp.size() - 1; i++) {
		if (temp[i] < temp[i + 1] && temp[i] < temp[i - 1]) continue;
		if (temp[i] > temp[i + 1] && temp[i] > temp[i - 1]) continue;
		return false;
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr);
	vector<int> b(n), c(n);
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (idx >= n) idx = 1;
		b[idx] = arr[i];
		idx += 2;
	}
	idx = 1;
	for (int i = 0; i < n; i++) {
		if (idx >= n) idx = 0;
		c[idx] = arr[i];
		idx += 2;
	}
	if (check(b)) {
		for (auto x : b) cout << x << " ";
		cout << endl;
		return;
	}
	if (check(c)) {
		for (auto x : c) cout << x << " ";
		cout << endl;
		return;
	}
	cout << -1 << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}