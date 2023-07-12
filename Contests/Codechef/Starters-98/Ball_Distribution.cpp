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
		for (int i = 0; i < m; i++) {
			cin >> color[i];
		}
		sort(color.begin(), color.end());
		int arr[n][m];
		int l = 0;
		int j = 0;
		for (int i = m - 1; i >= 0; i--) {
			int k = color[i];
			while (k--) {
				arr[l++][j] = 1;
				if (l == n) {
					l = 0;
					j++;
				}
			}
		}
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][m - 1] == 1) {
				cnt++;
			}
			else {
				cout << cnt << endl;
				break;
			}
		}


	}

}