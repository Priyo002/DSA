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

#define MAX 1000010

bool isPrime[MAX];
int spf[MAX];

void seive() {
	fill(isPrime, isPrime + MAX, true);

	for (int i = 1; i < MAX; i++)
		spf[i] = i;

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i < MAX; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j < MAX; j += i) {
				if (isPrime[j])
					spf[j] = i;
				isPrime[j] = false;
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;

	unordered_map<int, int> mp;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		while (x != 1) {
			mp[spf[x]]++;
			x /= spf[x];
		}
	}

	for (auto x : mp) {
		if (x.second % n != 0) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();
	seive();
	int t;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}