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
	vector<int> even, odd;
	int first = -1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (first == -1) first = x;
		if (x & 1) odd.push_back(i + 1);
		else even.push_back(i + 1);
	}

	cout << n - 1 << endl;
	if (first & 1) {
		for (int i = odd.size() - 1; i >= 1; i--) {
			cout << odd[i] << " " << odd[i - 1] << endl;
		}
		for (int i = 0; i < even.size(); i++) {
			cout << 1 << " " << even[i] << endl;
		}
	}
	else {
		for (int i = even.size() - 1; i >= 1; i--) {
			cout << even[i] << " " << even[i - 1] << endl;
		}
		for (int i = 0; i < odd.size(); i++) {
			cout << 1 << " " << odd[i] << endl;
		}
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