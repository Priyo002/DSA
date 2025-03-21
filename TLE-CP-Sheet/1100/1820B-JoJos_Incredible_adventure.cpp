#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
#define rsort(X) sort(X.rbegin(),X.rend())
#define allRange(X) X.begin(),X.end()
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
	string s;
	cin >> s;

	int n = s.size();

	int len = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') continue;

		int j = i;
		int cnt = 0;
		while (j < n && s[j] == '1') {
			cnt++;
			j++;
		}
		len = max(cnt, len);
		i = j - 1;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') break;
		cnt++;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '0') break;
		cnt++;
	}

	cnt = min(n, cnt);
	len = max(len, cnt);

	if (len == n) {
		cout << n*n << endl;
	}
	else {

		len++;
		int l = len / 2;
		int b = len - l;

		cout << l*b << endl;
	}
}

int32_t main() {

	init();
	//clock_t time_req;
	//time_req = clock();

	int t = 1;
	cin >> t;
	while (t--)
		solve();

	//time_req = clock() - time_req;
	//cout << endl << "Time Taken is ";
	//cout << (float)time_req / CLOCKS_PER_SEC << " Seconds" << endl;

}