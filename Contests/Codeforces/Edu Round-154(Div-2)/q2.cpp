#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
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
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2) {
		cout << "YES" << endl;
		return;
	}
	for (int i = 0; i < s1.size() - 1; i++) {
		if (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '1') {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;

}
int32_t main() {

	init();

	int t;
	cin >> t;
	while (t--)
		solve();

}