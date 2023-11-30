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

int n = 1000006;
vector<bool> isPrime(n + 1, true);
void seive() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

int f(int n, int k) {
	if (n < 0) return INT_MAX;
	if (n == 0) return 0;
	if (isPrime[n]) return 1;

	return 1 + f(n - k, k * 2);
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	seive();

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int k = f(n, 1);
		cout << (k >= INT_MAX ? -1 :  k) << endl;
	}

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}