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
		int n;
		cin >> n;
		n = n - 1;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		bool flag = true;

		vector<int> ans(2 * 1e5, 0);
		if (arr[0] == 1) {
			ans[1]++;
		}
		for (int i = 1; i < n ; i++) {
			int d = arr[i] - arr[i - 1];
			if (d > (2 * n + 1)) {
				cout << "NO" << endl;
				flag = false;
				break;
			}
			ans[d]++;
		}
		if (flag == false) continue;
		int m = *max_element(ans.begin(), ans.end());
		if (m > 1) {
			cout << "NO";
		}
		else cout << "YES";
		cout << endl;
	}

}