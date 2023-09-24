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

void gray(int n, int k) {
	string s = "";
	if (k & (1 << (n - 1))) {
		s += "1";
	}
	else s += "0";
	for (int i = n - 1; i > 0; i--) {
		int t1, t2;
		if ((k & (1 << i))) t1 = 1;
		else t1 = 0;
		if (k & (1 << (i - 1))) t2 = 1;
		else t2 = 0;
		if (t1 == t2) {
			s += "0";
		}
		else s += "1";
	}
	cout << s << endl;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		gray(n, i);
	}
}

int32_t main() {

	init();
	solve();

}