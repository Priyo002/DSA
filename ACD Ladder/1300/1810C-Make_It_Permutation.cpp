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
	int n, c, d, ans = 0;
	cin >> n >> c >> d;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr);
	vector<int> v = {arr[0]};
	for (int i = 1; i < n; i++) {
		if (v.back() != arr[i]) v.push_back(arr[i]);
		else ans += c;
	}

	int mn = INF;
	for (int i = 0; i < v.size(); i++) {

		int ins = (v[i] - i - 1) * d;
		int del = (v.size() - i - 1) * c;
		mn = min(mn, ans + ins + del);
	}
	cout <<  min(mn, n * c + d) << endl;
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
