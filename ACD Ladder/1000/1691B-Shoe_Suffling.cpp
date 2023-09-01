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
	unordered_map<int, int> mp;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	for (auto x : mp) {
		if (x.second == 1) {
			cout << -1 << endl;
			return;
		}
	}
	vector<int> ans(n);
	int idx = -1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1]) {
			if (idx == -1) idx = i;
			ans[i] = i + 1;
		}
		else {
			ans[i] = idx;
			idx = -1;
		}
	}
	ans[n - 1] = idx;
	for (auto x : ans) cout << x + 1 << " ";
	cout << endl;

}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}