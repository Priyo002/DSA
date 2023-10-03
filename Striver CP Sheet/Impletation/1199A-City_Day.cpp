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
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		int mini = v[i];
		bool flag = true;
		for (int j = (i - x < 0 ? 0 : i - x); j < i; j++) {
			if (mini < v[j]) continue;
			flag = false;
		}
		for (int j = i + 1; j <= (i + y >= n ? n - 1 : i + y); j++) {
			if (mini < v[j]) continue;
			flag = false;
		}
		if (flag) {
			cout << i + 1 << endl;
			return;
		}
	}
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();


	solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}