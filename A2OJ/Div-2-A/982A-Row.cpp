#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

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
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n == 1) {
		if (s[0] == '0') cout << "NO";
		else cout << "YES";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (s[i] == s[i + 1]) {
				cout << "NO";
				return;
			}
		}
		else if (i == n - 1) {
			if (s[i] == s[i - 1]) {
				cout << "NO";
				return;
			}
		}
		else {
			if (s[i] == '1') {
				if (s[i] == s[i + 1] || s[i] == s[i - 1]) {
					cout << "NO";
					return;
				}
			}
			else {
				if (s[i] == s[i + 1] && s[i] == s[i - 1]) {
					cout << "NO";
					return;
				}
			}
		}
	}
	cout << "YES";
}

int main() {

	init();

	solve();

}