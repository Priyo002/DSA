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
	int n = s1.size();
	string t1 = s1, t2 = s2;
	for (int i = 0; i < n; i++) {
		if (t1[i] == '1') {
			for (int j = i + 1; j < n; j++) {
				t1[j] = '1';
			}
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		if (t2[i] == '1') {
			for (int j = i + 1; j < n; j++) {
				t2[j] = '1';
			}
			break;
		}
	}
	if (t1 == t2) {
		cout << "YES" << endl;
		return;
	}
	t1 = s1; t2 = s2;
	for (int i = n - 2; i >= 0; i--) {
		if (t1[i] == '0') {
			for (int j = i - 1; j >= 0; j--) {
				t1[j] = '0';
			}
			break;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (t2[i] == '0') {
			for (int j = i - 1; j >= 0; j--) {
				t2[j] = '0';
			}
			break;
		}
	}
	if (t1 == t2) {
		cout << "YES" << endl;
		return;
	}
	t1 = s1, t2, s2;
	for (int i = 0; i < n; i++) {
		if (t1[i] == '1') {
			for (int j = i + 1; j < n; j++) {
				t1[j] = '1';
			}
			break;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (t2[i] == '0') {
			for (int j = i - 1; j >= 0; j--) {
				t2[j] = '0';
			}
			break;
		}
	}
	if (t1 == t2) {
		cout << "YES" << endl;
		return;
	}
	t1 = s1, t2 = s2;
	for (int i = n - 2; i >= 0; i--) {
		if (t1[i] == '0') {
			for (int j = i - 1; j >= 0; j--) {
				t1[j] = '0';
			}
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (t2[i] == '1') {
			for (int j = i + 1; j < n; j++) {
				t2[j] = '1';
			}
			break;
		}
	}
	if (t1 == t2) {
		cout << "YES" << endl;
		return;
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