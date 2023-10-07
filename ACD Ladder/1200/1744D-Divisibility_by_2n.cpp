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
	vector<int> arr(n + 1), b;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i % 2 == 0) {
			int l = 0;
			int j = i;
			while (j > 0 && j % 2 == 0) {
				l++;
				j /= 2;
			}
			b.push_back(l);
		}
		int temp = arr[i];
		while (temp > 0 && temp % 2 == 0) {
			cnt++;
			temp /= 2;
		}
	}
	sort(b);
	if (cnt >= n) {
		cout << 0 << endl;
	}
	else {
		int op = 0;
		int need = n - cnt;

		for (int i = b.size() - 1; i >= 0; i--) {
			op++;
			if (need <= b[i]) {
				cout << op << endl;
				return;
			}
			need -= b[i];
		}

		cout << -1 << endl;

	}

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