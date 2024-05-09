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
	int n, a, b;
	cin >> n >> a >> b;

	vector<int> arr(n + 1);

	for (int i = 1; i <= n; i++) cin >> arr[i];

	vector<int> pref = arr;

	for (int i = 2; i <= n; i++) {
		pref[i] += pref[i - 1];
	}

	multiset<int> mt;

	for (int i = a; i <= b; i++) {
		mt.insert(pref[i]);
	}

	int ans = LLONG_MIN;

	for (int i = 1; i <= n - a + 1; i++) {
		ans = max(ans, *mt.rbegin() - pref[i - 1]);

		mt.erase(mt.find(pref[i + a - 1]));
		if (i + b <= n) {
			mt.insert(pref[i + b]);
		}
	}

	cout << ans;
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