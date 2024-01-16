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

	string a, b;
	cin >> a >> b;
	//cout << a << " " << b << endl;

	int one = 0, zero = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) continue;
		if (a[i] == '1') {
			one++;
		}
		else zero++;
	}
	if (one == 0) {
		cout << zero << endl;
	}
	else if (zero == 0) {
		cout << one << endl;
	}
	else if (zero == one) {
		cout << zero << endl;
	}
	else if (zero > one) {
		cout << (zero - one) + one  << endl;
	}
	else cout << (one - zero) + zero << endl;

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