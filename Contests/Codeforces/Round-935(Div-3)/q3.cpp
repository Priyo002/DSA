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

	int zero = 0, one = 0;

	for (auto ch : s) {
		zero += (ch == '0');
		one += (ch == '1');
	}

	vector<int> ans;

	int temp = ceil((1.0) * (n) / 2.0);

	if (one >= temp) {
		ans.push_back(0);
	}

	int cnt0 = 0, cnt1 = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			cnt0++;
		}
		else {
			cnt1++;
		}

		int left1 = one - cnt1;

		int k1 = ceil((1.0) * (i + 1) / 2.0);
		int k2 = ceil((1.0) * (n - (i + 1)) / 2.0);

		if (cnt0 >= k1 && left1 >= k2) {
			ans.push_back(i + 1);
		}
	}

	double mid = (1.0 * n) / 2.0;

	int t = ans[0];

	double mn = abs((1.0 * ans[0]) - mid);

	for (int i = 1; i < ans.size(); i++) {
		double t1 = abs((1.0 * ans[i]) - mid);
		if (t1 < mn) {
			t = ans[i];
			mn = t1;
		}
	}


	cout << t << endl;
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