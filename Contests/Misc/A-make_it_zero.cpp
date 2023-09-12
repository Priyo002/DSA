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
	int sum;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	if (n & 1) {
		cout << 4 << endl;
		cout << 1 << " " << n << endl;
		cout << 1 << " " << n - 1 << endl;
		cout << n - 1 <<  " " << n << endl;
		cout << n - 1 << " " << n << endl;
	}
	else {
		cout << 2 << endl;
		cout << 1 << " " << n << endl;
		cout << 1 << " " << n << endl;

	}
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}