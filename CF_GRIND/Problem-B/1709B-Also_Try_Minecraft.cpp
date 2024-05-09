#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int long long
#define pb push_back
#define endl '\n'
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
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> pref, suff;

	for (int i = n - 1; i > 0; i--) {
		suff.push_back(max(0LL, arr[i] - arr[i - 1]));
	}
	reverse(suff.begin(), suff.end());

	for (int i = 0; i < n - 1; i++) {
		pref.push_back(max(0LL, arr[i] - arr[i + 1]));
	}
	for (int i = 1; i < pref.size(); i++) {
		pref[i] += pref[i - 1];
		suff[i] += suff[i - 1];
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;

		if (r > l) {
			l--, r -= 2;

			cout << pref[r] - (l ? pref[l - 1] : 0) << endl;
		}
		else {

			r--, l -= 2;

			cout << suff[l] - (r ? suff[r - 1] : 0) << endl;
		}


	}
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int _t = 1;
	//cin >> _t;
	while (_t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}