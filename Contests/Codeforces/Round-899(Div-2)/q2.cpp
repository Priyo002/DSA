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
	int n, a;
	cin >> n;
	vector<vector<int>> arr(n);
	unordered_map<int, unordered_set<int>> mp;
	for (int j = 0; j < n; j++) {
		int k;
		cin >> k;
		vector<int> temp;
		for (int i = 0; i < k; i++) {
			cin >> a;
			mp[a].insert(j);
			temp.pb(a);
		}
		arr[j] = temp;
	}
	vector<int> unio;
	int ans = INT_MIN;
	for (auto x : mp) {
		unordered_set<int> temp;
		for (int i = 0; i < n; i++) {
			if (mp[x.first].count(i) == 0) {
				for (int j = 0; j < arr[i].size(); j++) {
					temp.insert(arr[i][j]);
				}
			}
		}
		unio.pb(temp.size());
	}
	for (int i = 0; i < unio.size(); i++) {
		if (unio[i] != mp.size()) ans = max(ans, unio[i]);
	}
	cout << ans << endl;
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}