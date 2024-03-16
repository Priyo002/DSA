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
	int one = 0, two = 0, m = 0;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == 1) {
			one++;
		}
		else {
			if (x > 2) {
				m += (x - 2);
			}
			two++;
		}
	}

	int a = 0, b = 0;
	a += (one + 1) / 2 , b += one / 2;
	bool f = false;
	f = one % 2;

	if (f) {
		if (m & 1) {
			f = false;
		}
	}
	else {
		if (m & 1) {
			f = true;
		}
	}
	if (f) {
		a += two;
	}
	else {
		b += two;
	}
	if (a == b) {
		cout << "DRAW";
	}
	else if (a > b) {
		cout << "Alice";
	}
	else cout << "Bob";
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