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
	vector<int> s(n), e(n);
	for (int i = 0; i < n; i++) cin >> s[i] >> e[i];

	bool flag = false;
	unordered_map<int, int> mps;
	mps[s[0]] = 0;
	for (int i = 1; i < n; i++) {
		if (s[i] >= s[0] && e[i] >= e[0]) {
			flag = true;
		}
		mps[s[i]] = i;
	}
	if (flag) {
		cout << -1 << endl;
		return;
	}
	for (int i = s[0] - 1; i >= 1; i--) {
		if (mps.find(i) == mps.end()) {
			cout << i << endl;
			return;
		}
		else {
			int idx = mps[i];
			if (e[idx] < e[0]) {
				cout << i << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}