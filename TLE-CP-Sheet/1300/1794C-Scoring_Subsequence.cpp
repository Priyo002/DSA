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

vector<int> arr;

int f(int i, int j) {
	int ans = 0;

	int k = j;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (arr[mid] >= k - mid + 1) {
			ans = k - mid + 1;
			j = mid - 1;
		}
		else {
			i = mid + 1;
		}
	}
	return ans;
}

void solve() {
	arr.clear();

	int n;
	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) {
		cout << f(0, i) << " ";
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