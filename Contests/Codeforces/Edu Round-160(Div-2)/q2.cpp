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
	string s;
	cin >> s;
	int one = 0;
	int zero = 0;
	for (auto ch : s) {
		if (ch == '1') one++;
		else zero++;
	}
	if (!zero || !one) {
		cout << s.size() << endl;
		return;
	}
	if (zero == one) {
		cout << 0 << endl;
		return;
	}
	int idx = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') continue;
		if (idx != -1) {
			idx = i;
			break;
		}
		zero--;
		if (zero == 0) {
			idx = i;
		}
	}
	cout << s.size() - idx << endl;

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