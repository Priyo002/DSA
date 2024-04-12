#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
#define rsort(X) sort(X.rbegin(),X.rend())
#define allRange(X) X.begin(),X.end()
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

	vector<int> arr(n), brr(n);

	for (auto &i : arr) cin >> i;

	for (auto &i : brr) cin >> i;

	sort(arr), sort(brr);

	vector<int> temp;

	for (auto x : brr) {
		int idx = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
		int cnt = (n - 1) - idx + 1;

		temp.push_back(cnt);
	}

	int ans = 1, j = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans = (((ans % mod) * ((temp[i] - j) % mod)) % mod);
		j++;
	}

	cout << ans << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t = 1;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}