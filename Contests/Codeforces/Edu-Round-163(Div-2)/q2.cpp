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

	vector<int> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	int mx = -1;

	for (auto x : arr) {
		string s = to_string(x);
		bool flag = false;
		if ((int)s.size() > 1) {
			int fi = s[0] - '0';
			int se = s[1] - '0';

			if (fi <= se) {
				if (mx <= fi && mx <= se) {
					mx = max(mx, se);
					flag = true;
				}
				else if (mx <= x) {
					mx = max(mx, x);
					flag = true;
				}
			}
			else {
				if (mx <= x) {
					mx = max(mx, x);
					flag = true;
				}
			}
		}
		else {
			if (mx <= x) {
				mx = max(mx, x);
				flag = true;
			}
		}
		if (!flag) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
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