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

int powr(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b = (b >> 1);
	}
	return res;
}

void solve() {
	int n;
	cin >> n;

	auto idx = lower_bound(arr.begin(), arr.end(), n) - arr.begin();
	if (idx == (int)(arr.size())) {
		cout << "NO" << endl;
		return;
	}
	if (arr[idx] == n) {
		cout << "YES" << endl;
		return;
	}

	for (int i = 0; i < idx; i++) {
		int k = i + 2;
		int j = 3;
		while (true) {
			int m = (powr(k, j) - 1) / (k - 1);
			if (m == n) {
				cout << "YES" << endl;
				return;
			}
			if (m > n) break;
			j++;
		}
	}
	cout << "NO" << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	arr.clear();
	int k = 2;
	while (true) {
		int t = ((k * k * k) - 1) / (k - 1);
		if (t > 1000000) break;
		arr.push_back(t);
		k++;
	}

	int t;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}