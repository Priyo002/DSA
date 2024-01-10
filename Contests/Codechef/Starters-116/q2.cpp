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
	int n, x;
	cin >> n >> x;
	string s;
	cin >> s;

	if (s[0] == '0') {
		cout << "NO" << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		char ch = s[i];
		if (ch == '0') {
			int cnt = 0;
			int j = i;
			while (j < n && s[j] == ch) {
				cnt++;
				j++;
			}
			if (cnt > x) {
				cout << "NO" << endl;
				return;
			}
			i = j - 1;
		}
	}
	cout << "YES" << endl;
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