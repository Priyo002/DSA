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
	int n, m;
	cin >> n >> m;
	string s1 = "", s2 = "";
	for (int i = 0; i < m; i++) {
		s1 += "#";
		s2 += ".";
	}
	string s3 = s2;
	s3[0] = '#';
	s2[m - 1] = '#';
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			if (flag) {
				cout << s2;
				flag = false;
			}
			else if (flag == false) {
				cout << s3;
				flag = true;
			}
		}
		else {
			cout << s1;

		}
		cout << endl;
	}
}

int32_t main() {

	init();

	solve();

}