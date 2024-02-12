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
	for (int i = 0; i < n; i++) cin >> arr[i];

	vector<int> pref(n);
	unordered_set<int> st;

	vector<int> temp;

	pref[0] = 0;
	for (int i = 1; i < n; i++) {
		pref[i] = pref[i - 1];

		if (arr[i] != arr[i - 1]) {
			pref[i]++;
			temp.push_back(i - 1);
		}

	}

	// for (auto x : temp) cout << x << " ";
	// cout << endl;
	// return;

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;

		int cnt = pref[r];
		cnt -= pref[l];

		if (cnt == 0) {
			cout << -1 << " " << -1;
		}
		else {

			int lo = lower_bound(temp.begin(), temp.end(), l) - temp.begin();
			if (lo + 1 <= r) {
				cout << lo + 2 << " " << lo + 3;
			}
		}
		cout << endl;
	}
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