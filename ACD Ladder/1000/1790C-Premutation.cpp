#include "bits/stdc++.h"
using namespace std;
int n;

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
	cin >> n;
	vector<vector<int>>perm(n, vector<int>(n - 1));
	vector<int>p(n, 0);
	vector<int>cnt(n + 1, 0);
	for (int i = 0; i < n; i++) {
		p[i] = i + 1;
		for (int j = 0; j < n - 1; j++) {
			cin >> perm[i][j];
			if (j == 0) cnt[perm[i][j]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == n - 1) {
			p[0] = i;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		if (perm[i][0] != p[0]) {
			for (int j = 0; j < n - 1; j++) {
				p[j + 1] = perm[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) cout << p[i] << ' ';
	cout << endl;

}

int main() {

	init();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}