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
	int n, x;
	cin >> n >> x;
	vector<int> arr;
	arr.pb(0);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		arr.push_back(k);
	}
	arr.push_back(x);

	int ans = INT_MIN;
	for (int i = 0; i < arr.size() - 1; i++) {
		if (i + 1 == arr.size() - 1) ans = max(ans, 2 * (arr[i + 1] - arr[i]));
		else
			ans = max(ans, arr[i + 1] - arr[i]);
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