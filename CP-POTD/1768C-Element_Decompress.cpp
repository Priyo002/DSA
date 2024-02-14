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
	unordered_map<int, list<int>> mp;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]].push_back(i);
	}

	vector<int> temp = arr;
	sort(arr);

	unordered_set<int> a1, b1;
	vector<int> a(n, 0), b(n, 0);

	for (int i = 0; i < n; i++) {
		if (arr[i] > n) {
			cout << "NO" << endl;
			return;
		}
		if (a1.count(arr[i]) == 0) {
			a[i] = arr[i];
			a1.insert(arr[i]);
		}
		else if (b1.count(arr[i]) == 0) {
			b[i] = arr[i];
			b1.insert(arr[i]);
		}
		else {
			cout << "NO" << endl;
			return;
		}
	}

	set<int> a2, b2;
	for (int i = 1; i <= n; i++) {
		if (a1.count(i) == 0) {
			a2.insert(i);
		}
		if (b1.count(i) == 0) {
			b2.insert(i);
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (a2.size() == 0) {
				cout << "NO" << endl;
				return;
			}
			a[i] = *a2.begin();
			a2.erase(a[i]);
			if (a[i] > b[i]) {
				cout << "NO" << endl;
				return;
			}
		}
		else {
			if (b2.size() == 0) {
				cout << "NO" << endl;
				return;
			}
			b[i] = *b2.begin();
			b2.erase(b[i]);
			if (b[i] > a[i]) {
				cout << "NO" << endl;
				return;
			}
		}
	}

	unordered_map<int, list<int>> mp1;
	vector<pair<int, int>> ans(n);

	for (int i = 0; i < n; i++) {
		int ele = max(a[i], b[i]);

		int idx = mp[ele].back();
		mp[ele].pop_back();

		ans[idx] = {a[i], b[i]};

	}

	cout << "YES" << endl;
	for (auto x : ans) {
		cout << x.first << " ";
	}
	cout << endl;
	for (auto x : ans) {
		cout << x.second << " ";
	}
	cout << endl;
}

int32_t main() {

	init();
	clock_t time_req;
	time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	time_req = clock() - time_req;
	cout << endl << "Time Taken is ";
	cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}