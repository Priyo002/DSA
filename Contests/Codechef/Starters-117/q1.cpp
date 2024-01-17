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
	int h, x, y1, y2, k;
	cin >> h >> x >> y1 >> y2 >> k;

	int s1, s2;
	if (h % x == 0) {
		s1 = h / x;
	}
	else s1 = h / x + 1;

	int temp = k * y1;
	if (temp >= h) {
		if (h % y1 == 0) {
			s2 = h / y1;
		}
		else s2 = h / y1 + 1;
	}
	else {
		int l = h - temp;
		if (l % y2 == 0) {
			s2 = l / y2 + k;
		}
		else s2 = l / y2 + 1 + k;
	}
	cout << min(s1, s2) << endl;

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