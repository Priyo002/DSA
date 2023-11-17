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
	for (auto&x : arr) cin >> x;

	int sum = 0, ans = INT_MIN;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			sum += arr[i];
		}
		else {
			if ((arr[i - 1] & 1) == (arr[i] & 1)) {
				sum = arr[i];
			}
			else sum += arr[i];
		}
		if (arr[i] >= 0) flag = true;
		ans = max(ans, sum);
		if (sum < 0) sum = 0;
	}
	if (flag == false) {
		cout << *max_element(arr.begin(), arr.end());
	}
	else cout << ans;
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