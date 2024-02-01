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
	int n, m;
	cin >> n >> m;

	unordered_map<int, int> mp;
	unordered_set<int> st;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x % m]++;
		st.insert(x % m);
	}

	int ans = 0;

	if (mp.count(0)) {
		mp.erase(0);
		st.erase(0);
		ans++;
	}
	if (m % 2 == 0 && mp.count(m / 2)) {
		mp.erase(m / 2);
		st.erase(m / 2);
		ans++;
	}

	for (auto x : st) {
		int rem = m - x;

		if (mp.count(rem) == 0) continue;
		if (mp.count(x) == 0) continue;

		int diff = abs(mp[rem] - mp[x]);
		if (diff == 0 || diff == 1) {
			mp.erase(rem), mp.erase(x);
			ans++;
		}
		else if (mp[rem] > mp[x]) {
			mp[rem] -= (mp[x] + 1);
			mp.erase(x);
			ans++;
		}
		else if (mp[x] > mp[rem]) {
			mp[x] -= (mp[rem] + 1);
			mp.erase(rem);
			ans++;
		}
	}

	for (auto x : mp) ans += x.second;

	cout << ans << endl;

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