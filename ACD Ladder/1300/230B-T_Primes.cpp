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

vector<bool> isPrime;

void seive() {
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= 1000005; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 1000005; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);

	for (auto&x : arr) cin >> x;

	for (auto x : arr) {
		int k = sqrt(x);
		if (x == 1) cout << "NO";
		else if ((k * k == x) && isPrime[k]) cout << "YES";
		else cout << "NO";
		cout << endl;
	}

}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();
	isPrime.resize(1000005, true);
	seive();
	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}