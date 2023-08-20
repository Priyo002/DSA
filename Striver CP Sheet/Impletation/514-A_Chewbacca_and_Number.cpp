#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define endl '\n'
#define sort(X) sort(X.begin(),X.end())
const int mod = 1e9 + 7;
const int INF = 1e18;

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
	if (s.size() == 1) {
		int t = s[0] - '0';
		if (t == 9 || t < 5) cout << t;
		else {
			cout << 9 - t;
		}
		return;
	}
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		int t = s[i] - '0';
		if (t >= 5) {
			if (i != 0 || t != 9)
				t = 9 - t;
		}
		sum = sum * 10 + t;
	}
	cout << sum;
}

int32_t main() {

	init();

	solve();

}