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
	int n, k;
	cin >> n >> k;

	k %= n;

	vector<int> arr(n);
	for (int i = 1; i <= n; i++) {
		arr[i - 1] = i;
	}

	while ((int)arr.size() > 1) {

		vector<int> brr;

		for (int i = 0; i < arr.size(); i++) {
			if ((i % k) == 0) {
				cout << arr[i] << " ";
			}
			else brr.pb(arr[i]);
		}

		if (((int)arr.size() & 1)) {
			int last = brr.back();
			brr.pop_back();
			arr.clear();
			arr.pb(last);

			for (auto x : brr) arr.pb(x);
		}
		else {
			arr = brr;
		}
		//k %= (arr.size());
	}
	for (auto x : arr) cout << x << " ";
	//cout << arr[0] << " ";
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}