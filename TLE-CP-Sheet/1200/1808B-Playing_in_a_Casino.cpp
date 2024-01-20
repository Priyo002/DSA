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
	int n, m;
	cin >> n >> m;

	vector<vector<int>> arr(m, vector<int>());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			arr[j].push_back(x);
		}
	}



	vector<vector<int>> b;
	for (int i = 0; i < m; i++) {
		sort(arr[i].begin(), arr[i].end());
		b.push_back(arr[i]);
		for (int j = n - 2; j >= 0; j--) {
			arr[i][j] += arr[i][j + 1];
		}
	}

	// for (int i = 0; i < m; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	//cout << endl << endl;

	int ans = 0;

	for (int i = 0; i < m; i++) {
		int temp = 0;
		for (int j = 0; j < n - 1; j++) {
			temp += (arr[i][j + 1] - (b[i][j] * (n - j - 1)));
		}
		ans += temp;
	}
	cout << ans << endl;
	// cout << endl;
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