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
	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int mx = 0;
	vector<int> temp(n);
	for (int i = 0; i < n; i++) {
		mx = max(mx, arr[i]);
		temp[i] = mx;
	}
	for (int i = 1; i < n; i++) {
		arr[i] += arr[i - 1];
	}

	vector<int> a;
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		int upper = upper_bound(temp.begin(), temp.end(), x) - temp.begin();
		upper--;
		if (upper < 0) cout << 0 << " ";
		else cout << arr[upper] << " ";
	}
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