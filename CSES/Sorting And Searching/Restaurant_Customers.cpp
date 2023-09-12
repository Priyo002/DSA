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
	vector<int> arr(n), leav(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i] >> leav[i];
	}
	sort(arr), sort(leav);
	int cnt = 0;
	int ans = INT_MIN;
	int i = 0, j = 0;
	while (i < n && j < n) {
		if (arr[i] < leav[j]) {
			cnt++;
			i++;
		}
		else {
			cnt--;
			j++;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}

int32_t main() {

	init();

	solve();

}