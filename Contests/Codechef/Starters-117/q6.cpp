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
}\

vector<vector<int>> arr;
vector<string> goose;
int n, m, k;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

int f(int i, int j) {
	if (i == n && j == m) {

	}
	int ans = INT_MAX;
	for (int d = 0; d < 4; d++) {
		int x = i + dir[d][0];
		int y = j + dir[d][1];

		if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] = ) {

		}
	}
	if (i + 1 < n) {

	}
	if (j + 1 < m) {

	}

}

void solve() {

	cin >> n >> m;

	arr.clear();
	arr.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	goose.clear();
	goose.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> goose[i];
	}

	cout << 1 << endl;

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