#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb emplace_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
//#define sort(X) sort(X.begin(),X.end())
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
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}

	vector<vector<int>> v(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		v[i][0] = arr[i];
		v[i][1] = brr[i];
		v[i][2] = i + 1;
	}

	sort(v.begin(), v.end(), [&](vector<int>&a, vector<int>&b) {
		return (a[0] - b[0] ) > (a[1] - b[1]);
	});

	vector<int> ans = {v[0][2]};

	for (int i = 1; i < n; i++) {
		if (v[0][0] - v[i][0] == v[0][1] - v[i][1]) {
			ans.push_back(v[i][2]);
		}
	}
	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (auto x : ans) cout << x << " ";
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