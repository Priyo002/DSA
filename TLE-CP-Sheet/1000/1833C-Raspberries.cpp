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

#define MAX 10000

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

void f(int n, vector<int>& brr) {

	while (spf[n] != 1) {
		brr.push_back(spf[n]);
		n /= spf[n];
	}
	// for (auto x : temp) {
	// 	cout << x << " ";
	// }
	//cout << endl;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int a = INT_MAX;

	for (int i = 0; i < n; i++) {
		int x = arr[i];
		int cnt = 0;
		while (x % k != 0) {
			x++;
			cnt++;
		}

		a = min(a, cnt);
	}

	vector<int> temp;

	f(k, temp);

	int ans = 0;
	for (int i = 0; i < temp.size(); i++) {

		int t = INT_MAX, idx = -1;
		for (int j = 0; j < arr.size(); j++) {
			int x = arr[j];
			if (x == -1) continue;
			int cnt = 0;
			while (x % temp[i] != 0) {
				cnt++;
				x++;
			}
			if (t > cnt) {
				t = cnt;
				idx = j;
			}

		}
		ans += t;
		arr[idx] = -1;
		//cout << idx << " ";
	}

	cout << min(a, ans) << endl;

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