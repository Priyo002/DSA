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
	string x, s;
	cin >> x >> s;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (x[i] == s[0]) {
			flag = true;
			string temp = "";
			int cnt = 0;
			for (int j = i; j < n && cnt < m; j++) {
				temp += x[j];
				cnt++;
			}
			if (temp == s) {
				cout << 0 << endl;
				return;
			}
		}
	}
	if (flag == false) {
		cout << -1 << endl;
		return;
	}
	int ans = 0;
	while (x.size() <= 1000 ) {
		ans++;
		x += x;
		//cout << x << " ";
		for (int i = 0; i < x.size(); i++) {
			if (x[i] == s[0]) {
				string temp = "";
				int cnt = 0;
				for (int j = i; j < x.size() && cnt < m; j++) {
					cnt++;
					temp += x[j];
				}
				if (temp == s) {
					cout << ans << endl;
					return;
				}
			}
		}
	}
	cout << -1 << endl;
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