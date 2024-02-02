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
	for (int i = 0; i < n; i++) cin >> arr[i];


	queue<int> qu;
	qu.push(0);
	vector<bool> visited(n, false);
	visited[0] = true;

	unordered_map<int, vector<int>> mp;

	while (qu.size()) {
		auto curr = qu.front();
		qu.pop();

		for (int i = 0; i < n; i++) {
			if (!visited[i] && arr[i] != arr[curr]) {
				mp[curr].push_back(i);
				qu.push(i);
				visited[i] = true;
			}
		}
	}

	for (auto x : visited) {
		if (!x) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	for (auto x : mp) {
		for (auto k : x.second) {
			cout << x.first + 1 << " " << k + 1 << endl;
		}
	}

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