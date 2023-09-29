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
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = {a, i};
	}
	sort(arr);
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		k -= arr[i].first;
		if (k >= 0) {
			ans.pb(arr[i].second + 1);
		}
		else break;
	}
	cout << ans.size() << endl;
	for (auto x : ans) cout << x << " ";

}


int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();


	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}