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
		int n, k;
		cin >> n >> k;
		vector<int> v(n), ans;
		int maxi = INT_MIN;
		int idx = -1;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			if (maxi < v[i]) {
				maxi = v[i];
				idx = i;
			}
		}
		v[idx] -= k;
		if (v[idx] <= 0) {
			ans.push_back(idx + 1);
		}
		while (true) {
			maxi = INT_MIN;
			for (int i = 0; i < n; i++) {
				if (maxi < v[i]) {
					maxi = v[i];
					idx = i;
				}
			}
			if (maxi <= 0) {
				break;
			}
			v[idx] -= k;
			if (v[idx] <= 0) {
				ans.push_back(idx + 1);
			}
		}
		for (auto i : ans) cout << i << " ";
		cout << endl;
	}

}