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

int powr(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res *= a;
		a *= a;
		b = (b >> 1);
	}
	return res;
}

void solve() {
	int x, y;
	cin >> x >> y;
	y -= x;
	int d = abs(y);
	int n = ceil(log(d) / log(2));
	n += (n + (y < 0) ) % 2 ;

	cout << 2 * (powr(2, n) - 1) + d;
}

int32_t main() {

	//init();
	//clock_t time_req;
	//time_req = clock();
	freopen("lostcow.in", "r", stdin);
	freopen("lostcow.out", "w", stdout);

	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}