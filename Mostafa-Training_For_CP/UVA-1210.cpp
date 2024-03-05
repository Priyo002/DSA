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

int isPrime[10011];
int k = 0;
void seive() {
	//cout << "HI";
	if (k > 0) return ;
	k++;

	int n = 10010;
	for (int i = 0; i <= n; i++) isPrime[i] = 1;

	isPrime[0] = isPrime[1] = 0;

	for (int i = 2; i * i <= n; i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				isPrime[j] = 0;
			}
		}
	}
}

void solve(int target) {
	unordered_map<int, int> mp;

	mp[0] = 1;
	int cnt = 0, prefSum = 0;

	for (int i = 2; i <= target; i++) {
		if (isPrime[i] == 0) continue;
		prefSum += i;
		int rem = prefSum - target;

		cnt += mp[rem];
		mp[prefSum]++;
	}
	cout << cnt << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();
	seive();
	int t;
	cout << "YES";
	return 0;
	while (true) {
		cin >> t;
		if (t == 0) break;
		solve(t);
	}

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}