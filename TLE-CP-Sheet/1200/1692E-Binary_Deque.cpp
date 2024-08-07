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
	int n, s;
	cin >> n >> s;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++) arr[i] += arr[i - 1];
	int sum = 0, len = 0;
	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
		if (arr[i] == s) {
			len  = i + 1;
		}
		int rem = arr[i] - s;
		if (mp.count(rem)) {
			len = max(len, i - mp[rem]);
		}
		if (mp.count(arr[i]) == 0) {
			mp[arr[i]] = i;
		}
	}


	if (arr[n - 1] < s) cout << -1 << endl;
	else cout << n - len << endl;
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