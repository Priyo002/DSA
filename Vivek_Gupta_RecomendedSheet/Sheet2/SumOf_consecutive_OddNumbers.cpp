#include<bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.in", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int sum = 0;
		if (n <= m) {
			for (int i = n + 1; i < m; i++) {
				if (i % 2 != 0) sum += i;
			}
		}
		else {
			for (int i = m + 1; i < n; i++) {
				if (i % 2 != 0) sum += i;
			}
		}
		cout << sum << endl;
	}

}