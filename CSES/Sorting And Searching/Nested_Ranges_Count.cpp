#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>

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
		int l, r;
		cin >> l >> r;
		arr[i][0] = l, arr[i][1] = r, arr[i][2] = i;
	}

	sort(arr.begin(), arr.end(), [](vector<int>&a, vector<int>&b) {
		if (a[0] == b[0]) {
			return a[1] > b[1];
		}
		return a[0] < b[0];
	});

	ordered_set st;

	vector<int> contains(n, 0), contained(n, 0);

	for (int i = n - 1; i >= 0; i--) {
		auto it = st.upper_bound({arr[i][1], LLONG_MAX});
		if (it != st.end()) {
			int cnt = st.order_of_key({it->first, it->second});
			contains[arr[i][2]] = cnt;
		}
		else {
			contains[arr[i][2]] = st.size();
		}
		st.insert({arr[i][1], i});
	}

	st.clear();

	for (int i = 0; i < n; i++) {
		auto it = st.lower_bound({arr[i][1], -1});
		if (it != st.end()) {
			int cnt = st.size() - st.order_of_key({it->first, it->second});
			contained[arr[i][2]] = cnt;
		}
		else {
			contained[arr[i][2]] = 0;
		}
		st.insert({arr[i][1], i});
	}

	for (auto x  : contains) {
		cout << x << " ";
	}
	cout << endl;
	for (auto x  : contained) {
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