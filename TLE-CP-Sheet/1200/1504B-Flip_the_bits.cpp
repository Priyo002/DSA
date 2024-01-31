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
	string a, b;
	cin >> a >> b;

	vector<pair<int, int>> arr;
	int j = 0;
	int one = 0, zero = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '1') one++;
		else zero++;

		if (one == zero) {
			arr.push_back({j, i});
			j = i + 1;
			one = zero = 0;
		}
	}

	for (auto it : arr) {
		int start = it.first;
		int end = it.second;

		if (a[start] != b[start]) {
			for (int i = start; i <= end; i++) {
				if (a[i] == '0') a[i] = '1';
				else a[i] = '0';
			}
		}
	}

	if (a == b) cout << "YES" << endl;
	else cout << "NO" << endl;
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