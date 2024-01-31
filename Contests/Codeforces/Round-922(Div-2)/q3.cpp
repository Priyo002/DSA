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
	int a, b, r;
	cin >> a >> b >> r;

	int x = max(a, b), y = min(a, b);
	bool flag = true;
	int k = 0;

	for (int i = 63; i >= 0; i--) {
		int abit = ((x >> i) & 1);
		int bbit = ((y >> i) & 1);

		if (abit == 1 && bbit == 0) {
			if (flag) {
				flag = false;
			}
			else {
				if ((k + (1ll << i)) <= r) {
					k += (1ll << i);
				}
			}
		}
	}

	cout << abs((x ^ k) - (y ^ k)) << endl;
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