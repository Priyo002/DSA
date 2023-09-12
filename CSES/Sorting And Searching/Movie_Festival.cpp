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
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = {a, b};
	}
	sort(arr);
	int mini = arr[0].second, cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		if (mini <= arr[i + 1].first) {
			mini = arr[i + 1].second;
			cnt++;
		}
		else {
			mini = min(mini, arr[i + 1].second);
		}
	}
	cout << cnt ;
}

int32_t main() {

	init();


	solve();

}