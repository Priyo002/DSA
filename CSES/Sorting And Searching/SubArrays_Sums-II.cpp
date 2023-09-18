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
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	vector<int> pref;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		pref.pb(sum);
	}
	int ans = 0;
	unordered_map<int, int> m;
	m[0]++;
	for (int i = 0; i < n; i++) {
		int target = pref[i] - k;
		ans += m[target];
		m[pref[i]]++;
	}
	cout << ans;
}

int32_t main() {

	init();


	solve();

}