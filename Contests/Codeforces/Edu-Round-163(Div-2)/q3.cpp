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

int n;
vector<vector<char>> arr;


bool f(int i, int j) {

	if (arr[i][j - 1] == '>') return true;
	return false;
}

void solve() {

	cin >> n;



	arr.clear();
	arr.resize(2, vector<char>(n));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	if (arr[1][n - 2] != '>') {
		cout << "NO" << endl;
		return;
	}

	int x = 1, y = n - 2;

	while (y > 0) {
		if (arr[(x ^ 1)][y - 1] == '>') {
			x ^= 1;//toggle
			y = y - 1;
		}
		else if (y >= 2 && arr[x][y - 2] == '>') {
			y -= 2;
		}
		else {
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;

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