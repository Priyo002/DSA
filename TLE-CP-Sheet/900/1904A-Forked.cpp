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
	int a, b, x1, y1, x2, y2;
	cin >> a >> b >> x1 >> y1 >> x2 >> y2;

	int dir[4][2] = {{ -1, -1}, {1, -1}, { -1, 1}, { 1 , 1 }};

	map<pair<int, int>, int> mp1, mp2;

	for (int i = 0; i < 4; i++) {
		mp1[ {x1 + dir[i][0]*a, y1 + dir[i][1]*b}]++;
		mp2[ {x2 + dir[i][0]*a, y2 + dir[i][1]*b}]++;

		mp1[ {x1 + dir[i][0]*b, y1 + dir[i][1]*a}]++;
		mp2[ {x2 + dir[i][0]*b, y2 + dir[i][1]*a}]++;
	}
	int ans = 0;
	for (auto x : mp1) {

		if (mp2.count(x.first)) ans++;
	}

	cout << ans << endl;
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