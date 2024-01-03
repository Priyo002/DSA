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
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<pair<int, int>> res;
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			res.push_back({arr[i - 1] - arr[i], i});
		}
	}

	sort(res);
	reverse(res.begin(), res.end());
	vector<int> ans(n);

	int cnt = n - 1;
	for (int i = 0; i < res.size(); i++) {
		ans[cnt] = res[i].second + 1;
		cnt--;
	}

	for (int i = 0; i < n; i++) {
		if (ans[i] == 0) {
			ans[i] = 1;
			cnt--;
		}
	}

	for (auto x : ans) cout << x << " ";
	cout << endl;
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