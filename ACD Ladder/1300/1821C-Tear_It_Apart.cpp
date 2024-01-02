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
	string s;
	cin >> s;

	int ans = INT_MAX;
	for (char ch = 'a'; ch <= 'z'; ch++) {
		int cnt = 0, window = 0;
		bool flag = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ch) {
				cnt++;
			}
			else {
				flag = true;
				cnt = 0;
			}
			window = max(window, cnt);
		}
		cnt = 0;
		if (window == 0 && flag) {
			ans = 0;
			continue;
		}
		while (window >= 1) {
			window /= 2;
			cnt++;
		}
		ans = min(ans, cnt);
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