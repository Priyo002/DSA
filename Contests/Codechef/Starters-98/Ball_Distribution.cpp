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
		vector<int> color(m);
		int sum = 0;
		for (int i = 0; i < m; i++) {
			cin >> color[i];
			sum += color[i];
		}

		int prod = n * m;
		cout << max(0, n - (prod - sum)) << endl;

	}

}