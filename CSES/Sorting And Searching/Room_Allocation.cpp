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

	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(3));

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		arr[i][2] = i;
	}

	sort(arr.begin(), arr.end(), [](vector<int>&a, vector<int>&b) {
		if (a[0] == b[0]) return a[1] < b[1];
		else return a[0] < b[0];
	});

	multiset<pair<int, int>> mt;

	int maxi = 0;
	vector<int> ans(n);

	for (int i = 0; i < n; i++) {
		auto it = mt.lower_bound({arr[i][0], -1});

		if (it == mt.begin()) {
			maxi++;
			ans[arr[i][2]] = maxi;

			mt.insert({arr[i][1], maxi});
		}
		else {
			it--;
			ans[arr[i][2]] = it->second;
			mt.insert({arr[i][1], it->second});
			mt.erase(it);
		}
	}

	cout << maxi << endl;
	for (auto x : ans) {
		cout << x << " ";
	}
	cout << endl;
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