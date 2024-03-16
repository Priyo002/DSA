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

void solve(int n) {
	int k = n;
	vector<int> arr;
	n = abs(n);
	while (n % 2 == 0) {
		arr.push_back(2);
		n /= 2;
	}

	for (int i = 3; i * i <= n; i += 2) {
		while (n % i == 0) {
			arr.push_back(i);
			n /= i;
		}
	}

	if (n > 2) arr.push_back(n);

	cout << k << " = ";
	if (k < 0) cout << -1 << " x ";

	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
		if (i != arr.size() - 1) {
			cout << " x ";
		}
	}
	cout << endl;
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t;
	while ((cin >> t) && t)
		solve(t);

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}