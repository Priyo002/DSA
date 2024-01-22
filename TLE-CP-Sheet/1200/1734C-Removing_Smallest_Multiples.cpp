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
	string s;
	cin >> s;

	unordered_set<int> st, has;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') continue;
		has.insert(i + 1);
		st.insert(i + 1);
		arr.push_back(i + 1);
	}
	int ans = 0;

	for (auto x : arr) {
		for (int i = x; i <= n; i += x) {
			if (has.find(i) != has.end()) {
				if (st.count(i)) {
					st.erase(i);
					ans += x;
				}
			}
			else break;
		}
	}
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