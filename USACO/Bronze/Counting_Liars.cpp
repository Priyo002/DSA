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
	vector<pair<int, char>> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		char dir;
		cin >> dir >> x;
		a[i] = {x, dir};
	}
	sort(a);
	int ans = n;
	for (int i = 0; i < n; i++) {
		int liars = 0;
		//count number of indices before me that say L
		for (int j = 0; j < i; j++)
			liars += (a[j].second == 'L' ? 1 : 0);
		//count the number of indices after me that say G
		for (int j = i + 1; j < n; j++)
			liars += (a[j].second == 'G' ? 1 : 0);
		ans = min(ans, liars);
	}
	cout << ans;

}

int32_t main() {

	//init();
	//clock_t time_req;
	//time_req = clock();


	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}