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
	for (int& i : arr) cin >> i;

	set<int> a, b;
	set<pair<int, int>> a2, b2;
	vector<int> a1(n, 0), b1(n, 0);

	set<int> a3, b3;
	for (int i = 1; i <= n; i++) {
		a3.insert(i);
		b3.insert(i);
	}

	for (int i = 0; i < n; i++) {
		if (a.count(arr[i])) {
			if (b.count(arr[i])) {
				cout << "NO" << endl;
				return;
			}
			b1[i] = arr[i];
			b2.insert({arr[i], i});
			b.insert(arr[i]);
			b3.erase(arr[i]);
		}
		else {
			a1[i] = arr[i];
			a2.insert({arr[i], i});
			a.insert(arr[i]);
			a3.erase(arr[i]);
		}
	}
	// for (auto x : a1) cout << x << " ";
	// cout << endl;
	// for (auto x : b1 ) cout << x << " ";
	// cout << endl;

	for (auto x : a2) {
		int idx = x.second;
		b1[idx] = *b3.begin();
		if (b1[idx] > a1[idx]) {
			cout << "NO" << endl;
			return;
		}
		b3.erase(b1[idx]);
	}
	for (auto x : b2) {
		int idx = x.second;
		a1[idx] = *a3.begin();
		if (a1[idx] > b1[idx]) {
			cout << "NO" << endl;
			return;
		}
		a3.erase(a1[idx]);
	}

	cout << "YES" << endl;
	for (auto x : a1) cout << x << " ";
	cout << endl;
	for (auto x : b1) cout << x << " ";
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