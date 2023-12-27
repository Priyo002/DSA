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
	unordered_map<int, int> mp;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (mp.count(x % 10) == 0) arr.push_back(x % 10);
		mp[x % 10]++;
	}
	if (mp[1] >= 3) {
		cout << "YES" << endl;
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (mp[i] >= 2) {
			for (auto x : arr) {
				if (x == i) continue;
				if ((2 * i + x) % 10 == 3) {
					cout << "YES" << endl;
					return;
				}
			}
		}
	}

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			for (int k = 0; k < arr.size(); k++) {
				if (i != j && i != k && j != k && (arr[i] + arr[j] + arr[k]) % 10 == 3) {
					cout << "YES" << endl;
					return;
				}
			}
		}
	}

	cout << "NO" << endl;
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