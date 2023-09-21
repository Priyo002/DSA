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

bool check(vector<int>& arr, int &h, int &x) {
	int sum = arr.size() * h;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] > h) sum -= h;
		else sum -= arr[i];
	}
	return sum <= x;
}

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int lo = 1;
	int hi = INT_MAX;
	int ans;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (check(arr, mid, x)) {
			ans = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	cout << ans << endl;
}

int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}