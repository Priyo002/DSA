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
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;


	sort(a), sort(b);

	int i = 0, j = n - 1;
	int p = 0, q = m - 1;
	int ans = 0;
	while (i <= j) {
		int k1 = abs(a[i] - b[q]);
		int k2 = abs(a[j] - b[p]);

		if (k1 >= k2) {
			ans += k1;
			i++, q--;
		}
		else {
			ans += k2;
			p++, j--;
		}

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