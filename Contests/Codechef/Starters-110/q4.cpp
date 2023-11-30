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
	int a, b;
	cin >> a >> b;
	if (a % b == 0) {
		cout << 0 << endl;
		return;
	}
	int x = a;
	int y = b;
	int cnt1 = 0, cnt2 = 0;
	bool f1 = false, f2 = false;

	while (x % y != 0 && y >= 1) {
		x++, y--;
		cnt1++;
	}
	if (x % y == 0) f1 = true;
	x = a;
	y = b;
	while (x % y != 0 && x >= 1) {
		x--, y++;
		cnt2++;
	}
	if (x % y == 0) f2 = true;
	if (f1 && f2) cout << min(cnt1, cnt2) << endl;
	else if (f1) cout << cnt1 << endl;
	else cout << cnt2 << endl;

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