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

int k = 0;
int isPrime[1299800];

void seive() {
	if (k > 0) return;

	k++;
	int n = 1299800;
	for (int i = 0; i < n; i++) isPrime[i] = 1;

	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				isPrime[j] = 0;
			}
		}
	}
}

void solve(int n) {
	if (isPrime[n] || n == 1) cout << 0 << endl;
	else {
		int upper = -1, lower = -1;
		for (int i = n; i <= 1299709; i++) {
			if (isPrime[i]) {
				upper = i;
				break;
			}
		}

		for (int i = n; i >= 0; i--) {
			if (isPrime[i]) {
				lower = i;
				break;
			}
		}

		cout << upper - lower << endl;
	}
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	seive();
	int n;
	while (true) {
		cin >> n;
		cout << " k " << k << " ";
		if (n == 0) break;
		solve(n);
	}

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}