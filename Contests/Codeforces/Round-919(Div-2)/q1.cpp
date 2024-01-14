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
	unordered_map<int, vector<int>> mp;

	for (int i = 0; i < n; i++) {
		int a, x;
		cin >> a >> x;
		mp[a].push_back(x);
	}

	int lower = 0;
	for (auto x : mp[1]) {
		lower = max(lower, x);
	}
	int upper = INT_MAX;
	for (auto x : mp[2]) {
		upper = min(upper, x);
	}

	if (lower > upper) {
		cout << 0 << endl;
		return;
	}

	int cnt = upper - lower + 1;
	for (auto x : mp[3]) {
		if (x >= lower && x <= upper) {
			cnt--;
		}
	}
	cout << max(0ll, cnt) << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}