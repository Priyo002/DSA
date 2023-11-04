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

int sum(string& str) {
	int s = 0;
	for (auto ch : str) {
		s += (ch - '0');
	}
	return s;
}

void solve() {
	int n, ans = 0;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<map<int, int>> mp(6);
	vector<pair<int, string>> vs;
	for (auto e : v) {
		vs.push_back({e.size(), e});
	}
	sort(vs);
	v.clear();
	for (auto e : vs) {
		v.push_back(e.second);
	}
	for (auto s : v) {
		int tot = 0;

		for (auto d : s) {
			tot += (d - '0');
		}
		int a = 0, b = 0;
		for (int len = s.size() + 2 - s.size() % 2; len <= 10; len += 2) {
			if (len > 2 * s.size()) break;
			a = 0;
			b = 0;
			for (int i = 0; i < s.size() - len / 2; i++) {
				a += s[i] - '0';
				b += s[s.size() - i - 1] - '0';
			}

			ans += mp[len - s.size()][tot - 2 * a];
			ans += mp[len - s.size()][tot - 2 * b];
		}
		mp[s.size()][tot]++;
		ans++;
	}
	cout << ans << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();


	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}