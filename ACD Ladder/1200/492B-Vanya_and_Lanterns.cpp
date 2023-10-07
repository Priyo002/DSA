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
	long double n, l;
	cin >> n >> l;
	vector<long double> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr);
	long double ans = 0;
	if (arr[0] != 0) {
		ans = arr[0];
	}
	if (arr.back() != l) {
		long double temp = l - arr[n - 1];
		if (temp > ans) ans = temp;
	}
	for (int i = 0; i < n - 1; i++) {
		long double temp = (arr[i + 1] - arr[i]) / 2.0;
		if (temp > ans) {
			ans = temp;
		}
	}
	cout << fixed << setprecision(9) << ans;
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