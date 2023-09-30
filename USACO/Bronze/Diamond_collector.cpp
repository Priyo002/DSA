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
	int n, k;
	cin >> n >> k;
	vector<int> diamonds(n);
	for (int &d : diamonds) { cin >> d; }

	int most = 0;
	/*
	 * Iterate through all diamonds and test setting them
	 * as the smallest diamond in the case.
	 */
	for (int x : diamonds) {
		int fittable = 0;
		/*
		 * Get all diamonds at least as large as x (including x itself)
		 * that differ from it by no more than k.
		 */
		for (int y : diamonds) {
			if (x <= y && y <= x + k) { fittable++; }
		}
		most = max(most, fittable);
	}
	cout << most;
}


int32_t main() {

	//init();
	//clock_t time_req;
	//time_req = clock();

	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}