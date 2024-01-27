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

//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n + 2, 0);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int L, R;
		cin >> L >> R;
		arr[L]++;
		arr[R + 1]--;
	}

	vector<int> query(n + 1, 0);
	query[arr[1]]++;
	for (int i = 2; i <= n; i++) {
		arr[i] += arr[i - 1];
		query[arr[i]]++;
	}
	for (int i = 1; i <= n; i++) {
		query[i] += query[i - 1];
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << query[n] - query[x - 1] << endl;
	}
}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}