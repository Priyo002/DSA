#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
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
	vector<int> arr(2 * n), v1, v2;
	for (int i = 0; i < 2 * n; i++) cin >> arr[i];

	sort(arr);
	n = n - 1;
	cout << arr[n + 1] - arr[n] << endl;

}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}