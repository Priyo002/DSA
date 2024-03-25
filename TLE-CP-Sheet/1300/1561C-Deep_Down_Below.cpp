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

int n;
vector<vector<int>> arr, brr;

bool f(int power) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (power > arr[i][j]) power++;
			else return false;
		}
	}

	return true;
}


void solve() {

	cin >> n;

	arr.clear();
	arr.resize(n, vector<int>());

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int a; cin >> a;
			arr[i].push_back(a);
		}
	}


	sort(arr.begin(), arr.end(), [&](vector<int>& a, vector<int>& b) {
		int mx1 = INT_MIN, mx2 = INT_MIN;

		for (int i = 0; i < a.size(); i++) {
			int x = a[i] - i;
			mx1 = max(mx1, x);
		}
		for (int i = 0; i < b.size(); i++) {
			int x = b[i] - i;
			mx2 = max(mx2, x);
		}

		if (mx1 == mx2) return a.size() > b.size();
		return mx1 < mx2;
	});



	int ans = 0;
	int lo = 1, hi = 1e9 + 1;

	while (lo <= hi) {

		int mid = (lo + hi) / 2;

		if (f(mid)) {
			ans = mid;
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

	cout << ans << endl;



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