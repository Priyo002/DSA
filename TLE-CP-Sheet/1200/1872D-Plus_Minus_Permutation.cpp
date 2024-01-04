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
	int n, x, y;
	cin >> n >> x >> y;

	int c = x * y / __gcd(x, y);

	int total = n * (n + 1) / 2;
	int t2 = n / c;

	int t1 = n / x - t2;
	int t3 = (n / y) - t2;
	int sumx = total - ((n - t1) * (n - t1 + 1) / 2);

	int sumy = t3 * (t3 + 1) / 2;
	//cout << t1 << " " << t2 << " " << t3 << " " << sumx << " " << sumy << endl;

	cout << sumx - sumy << endl;

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