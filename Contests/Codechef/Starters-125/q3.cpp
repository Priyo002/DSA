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

	string s;
	cin >> s;

	int cnt = 0;

	for (int i = 0; i < n; i++) cnt += (s[i] == '1');

	if (cnt <= k) {
		string str = "";
		int j = n - k;
		while (j--) {
			str += '0';
		}
		cout << str << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (s[i] == '1' && k) {
				s[i] = '0';
				k--;
			}
		}
		cout << s << endl;
	}
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