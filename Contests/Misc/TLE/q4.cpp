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


vector<int> dp;
void solve() {
	int n;
	cin >> n;
	unordered_map<int, int>mp;
	dp.clear();
	dp.resize(n + 1, 0);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 1) cnt++;
		if (a <= n)
			mp[a]++;
	}
	for (auto k : mp) {
		if (k.first == 1) continue;
		int l = k.first;
		int j = l;
		while (j <= n) {
			dp[j] += k.second;
			j += l;
		}
	}
	cout << *max_element(dp.begin(), dp.end()) + cnt << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}