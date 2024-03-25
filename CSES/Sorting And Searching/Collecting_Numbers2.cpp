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
	int n, q;
	cin >> n >> q;

	vector<int> values(n + 1), pos(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> values[i];
		pos[values[i]] = i;
	}

	int ans = 1;
	for (int i = 2; i <= n; i++) {
		if (pos[i - 1] > pos[i]) ans++;
	}

	while (q--) {
		int a, b;
		cin >> a >> b;

		set<pair<int, int>> st;

		if (values[a] + 1 <= n) {
			st.insert({values[a], values[a] + 1});
		}
		if (values[a] - 1 >= 1) {
			st.insert({values[a] - 1, values[a]});
		}
		if (values[b] + 1 <= n) {
			st.insert({values[b], values[b] + 1});
		}
		if (values[b] - 1 >= 1) {
			st.insert({values[b] - 1, values[b]});
		}

		for (auto p : st) {
			if (pos[p.first] > pos[p.second]) {
				ans--;
			}
		}

		swap(values[a], values[b]);

		pos[values[a]] = a;
		pos[values[b]] = b;

		for (auto p : st) {
			if (pos[p.first] > pos[p.second]) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}