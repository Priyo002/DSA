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
	int n, t;
	cin >> n >> t;
	vector<int> arr(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> arr[i];
	}
	t--;
	int k = 0;
	for (int i = 0; i < n;) {
		if (k + arr[i] == t) {
			cout << "YES";
			return;
		}
		k += arr[i];
		i = k;
		if (i >= n - 1 || i > t) break;
	}
	cout << "NO";
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