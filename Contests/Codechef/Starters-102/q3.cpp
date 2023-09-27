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
	int n, a;
	cin >> n;
	string arr;
	cin >> arr;
	vector<int> v;
	bool flag = false;
	for (int i = 2; i < n; i += 2) {
		int t1 = arr[i - 2] - '0';
		int t2 = arr[i - 1] - '0';
		int t3 = arr[i] - '0';
		//cout << t1 << " " << t2 << " " << t3 << endl;
		if (t1 == t2) {
			if (t1 == 1 && t3 == 0) {
				v.pb(1);
			}
			else if (t1 == 0 && t3 == 0) {
				v.pb(3);
			}
			else if (t1 == 0 && t3 == 1) {
				flag = true;
			}
		}
		else {
			if (t1 == 1 && t2 == 0 && t3 == 1) {
				v.pb(2);
			}
			else if (t1 == 1 && t2 == 0 && t3 == 0) {
				v.pb(1);
			}
			else if (t1 == 0 && t2 == 1 && t3 == 0) {
				v.pb(1);
			}
			else if (t1 == 0 && t2 == 1 && t3 == 1) {
				v.pb(2);
			}
		}
	}
	if (v.size() && flag == false) {
		int sum = 0;
		for (auto x : v)
			sum = ((sum % mod ) + (x % mod)) % mod;
		cout << sum << endl;
	}
	else cout << 0 << endl;

}

int32_t main() {

	init();
	// clock_t time_req;
	// time_req = clock();

	int t;
	cin >> t;
	while (t--)
		solve();

	// time_req = clock() - time_req;
	// cout << endl << "Time Taken is ";
	// cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}